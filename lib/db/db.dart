import 'package:flutter/foundation.dart';
import 'package:path/path.dart' as path_lib;
import 'package:sqflite/sqflite.dart';
import 'package:logging/logging.dart';
import 'package:sqflite_common_ffi/sqflite_ffi.dart';
import 'package:path_provider/path_provider.dart';
import 'dart:async';

class DBClassItemFields {
  static List<String> osab = ['id', 'val'];
  static List<String> devices = ['id', 'name', 'uuid'];
}

abstract class DataClass {
  List<dynamic> from(dynamic data);
  dynamic find(dynamic id);
  static String creator() {
    throw UnimplementedError();
  }
}

abstract class DBActions {
  bool checkEmpty();
}

class OSABData extends DataClass {
  @override
  List<OSABDataValues> from(dynamic data) {
    if (data == null) {
      return mList;
    }
    if (data is List<DBData?>) {
      data.map((e) {
        if (e != null) {
          mList.add(OSABDataValues(
              id: e["id"].toString(), value: e["value"].toString()));
        }
      });
    }
    if (data is DBData) {
      mList.add(OSABDataValues(
          id: data["id"].toString(), value: data["val"].toString()));
    } else {
      Logger("OSABData").warning("FAILED TO ACCEPT DATA");
    }
    return mList;
  }

  @override
  OSABDataValues find(var id) {
    return mList.firstWhere((element) => element.id == id.toString());
  }

  static String creator(String name) => '''
    CREATE TABLE IF NOT EXISTS $name (id TEXT PRIMARY KEY, val TEXT NOT NULL)
  ''';

  List<OSABDataValues> mList = [];
}

class OSABDataValues {
  OSABDataValues({required this.id, this.value});
  Map<String, String?> asMap() => {"id": id, "val": value};
  late String id;
  late String? value;
}

class DeviceData extends DataClass {
  @override
  List<DeviceDataValues> from(dynamic data) {
    void adder(Map e) {
      mList.add(DeviceDataValues(
          id: int.tryParse(e["id"].toString())!,
          name: e["name"].toString(),
          uuid: e["uuid"].toString()));
    }

    if (data == null) {
      return mList;
    }
    if (data is List<DBData?>) {
      data.map((e) {
        if (e != null) {
          adder(e);
        }
      });
    }
    if (data is DBData) {
      if (data.isEmpty) {
        return mList;
      }
      adder(data);
    } else {
      Logger("OSABData").warning("FAILED TO ACCEPT DATA");
    }
    return mList;
  }

  @override
  find(id) {
    return mList.firstWhere((element) => element.id == int.tryParse(id));
  }

  static String creator(String name) => '''
    CREATE TABLE IF NOT EXISTS $name (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      uuid TEXT NOT NULL,
      name TEXT NOT NULL
    )
  ''';

  List<DeviceDataValues> mList = [];
}

class DeviceDataValues {
  DeviceDataValues({required this.id, this.uuid, required this.name});
  Map<String, Object?> asMap() => {
        "id": id,
        "name": name,
        "uuid": uuid,
      };

  late int id;
  late String name;
  late String? uuid;
  late int? date;
}

class DBClass {
  DBClass(
      {required this.path,
      this.fDebug = false,
      required this.tableName,
      required itemFields,
      required this.creator}) {
    if (kDebugMode) {
      print("$tableName: $path");
    }
    this.itemFields = [...itemFields]; // Can't pass by ref
    if (!this.itemFields.remove('id')) {
      this.itemFields.removeAt(0);
    }
  }

  static Future<String> createPath(String name) async {
    final String dirPath = (await getApplicationSupportDirectory()).path;
    return path_lib.join(dirPath, name);
  }

  Future<DBClass> openDB() async {
    db = await dbFFi.openDatabase(path);
    db!.execute(creator(tableName));
    return this;
  }

  Future<bool> closeDB() async {
    _checkDBNull();
    if (db!.isOpen) {
      db!.close();
    }
    return true;
  }

  Future<List<DBData?>> get(List<String> column,
      {String? where, List<Object>? whereArgs}) async {
    _checkDBNull();
    return await db!.query(tableName, where: where, whereArgs: whereArgs);
  }

  Future<DBData?> getItem(String id) async {
    _checkDBNull();
    var data = await get(itemFields, where: "id = ?", whereArgs: [id]);
    return (data.isEmpty) ? {} : data.first;
  }

  Future<void> rmItem(String id) async {
    _checkDBNull();
    await rm(where: "id = ?", whereArgs: [id]);
  }

  Future<void> set(DBData values) async {
    _checkDBNull();
    db!.insert(tableName, values, conflictAlgorithm: ConflictAlgorithm.replace);
  }

  Future update(List<DBData> data) async {
    _checkDBNull();
  }

  Future rm({String? where, List<Object>? whereArgs}) async {
    _checkDBNull();
    await db!.delete(tableName, where: where, whereArgs: whereArgs);
  }

  Future deleteDB() async {
    _checkDBNull();
    await db!.delete(tableName);
    db!.close();
    await dbFFi.deleteDatabase(path);
    if (kDebugMode) {
      print("DATA TABLE $tableName DELETED");
    }
  }

  Future<int> getCount({String column = "*"}) async {
    if (!_checkDBNull()) {
      return -1;
    }
    return Sqflite.firstIntValue(
            await db!.rawQuery("SELECT COUNT(*) FROM $tableName")) ??
        0;
  }

  bool _checkDBNull() {
    if (db == null) {
      Logger("db is null");
      return false;
    }
    return true;
  }

  final String tableName;

  final String path;
  final bool fDebug;
  final dbFFi = databaseFactoryFfi;
  Database? db;
  final Function(String) creator;
  List<String> itemFields = [];
}

typedef DBData = Map<String, Object?>;

class DBInstances {
  static Future<DBClass> osab() async => DBClass(
          path: await DBClass.createPath("db.sql"),
          tableName: "OSAB",
          creator: OSABData.creator,
          itemFields: DBClassItemFields.osab)
      .openDB();
  static Future<DBClass> devices() async => DBClass(
          path: await DBClass.createPath("db.sql"),
          tableName: "DEV",
          creator: DeviceData.creator,
          itemFields: DBClassItemFields.devices)
      .openDB();
}
