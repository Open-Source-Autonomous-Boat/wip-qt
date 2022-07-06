import 'dart:developer';

import 'package:flutter/foundation.dart';
import 'package:path/path.dart';
import 'package:sqflite/sqflite.dart';
import 'package:sqflite_common_ffi/sqflite_ffi.dart';
import 'package:path_provider/path_provider.dart';
import 'dart:async';

class _OSABPaths {
  static Future<String> get path async =>
      (await getApplicationSupportDirectory()).path;
}

abstract class DBClass {
  DBClass({required this.mPath, this.fDebug = false, required this.mTableName});

  Future<DBClass> openDB();

  Future<bool> closeDB() async {
    _checkDBNull();
    if (mDB!.isOpen) {
      mDB!.close();
    }
    return true;
  }

  Future<List<DBData>> get(List<String> aColumn,
      {String? aWhere, List<Object>? aWhereArgs}) async {
    _checkDBNull();
    var val = mDB!.query(mTableName,
        columns: aColumn, where: aWhere, whereArgs: aWhereArgs);
    return val;
  }

  Future<T?> getItem<T>(List<String> aID) async {
    _checkDBNull();
    return null;
  }

  Future set(DBData aValues) async {
    _checkDBNull();
    await mDB!.insert(mTableName, aValues,
        conflictAlgorithm: ConflictAlgorithm.replace);
  }

  Future update<T, B>(List<B> aID, DBData aValues) async {
    _checkDBNull();
  }

  Future rm(String aName, {String? aWhere, List<Object>? aWhereArgs}) async {
    _checkDBNull();
    await mDB!.delete(mTableName, where: aWhere, whereArgs: aWhereArgs);
  }

  Future createDB() async {
    _checkDBNull();
  }

  Future deleteDB() async {
    _checkDBNull();
    await mDB!.delete(mTableName);
    mDB!.close();
    await mDBffi.deleteDatabase(mPath);
    if (kDebugMode) {
      print("DATABSE $mTableName DELETED");
    }
  }

  void _logError(String aMsg) {
    log(aMsg, time: DateTime.now());
  }

  void _checkDBNull() {
    if (mDB == null) {
      _logError("mDB is null");
    }
  }

  final String mTableName;

  final String mPath;
  final bool fDebug;
  final mDBffi = databaseFactoryFfi;
  Database? mDB;
}

class OSABDB extends DBClass {
  OSABDB(
      {required super.mPath, super.fDebug = false, required super.mTableName});

  @override
  Future<OSABDB> openDB() async {
    mDB = await mDBffi.openDatabase(mPath);
    createDB();
    return this;
  }

  @override
  Future createDB() async {
    super.createDB();
    mDB!.execute(
        'CREATE TABLE IF NOT EXISTS $mTableName (id TEXT PRIMARY KEY, val TEXT NOT NULL)');
  }

  @override
  Future<T?> getItem<T>(List<String> aID) async {
    super.getItem(aID);
    var val = await get(['val'], aWhere: 'id = ?', aWhereArgs: aID);
    return val.first['val'] as T;
  }

  @override
  Future update<T, B>(List<B> aID, DBData aValues) async {
    super.update(aID, aValues);
    await mDB!.update(mTableName, aValues, where: 'id = ?', whereArgs: aID);
  }

  static Future<OSABDB> getInstance() async {
    String path = join(await _OSABPaths.path, "db.sql");
    return OSABDB(mPath: path, mTableName: "OSAB").openDB();
  }
}

class DeviceDB extends DBClass {
  DeviceDB(
      {required super.mPath, super.fDebug = false, required super.mTableName});

  @override
  Future<DeviceDB> openDB() async {
    mDB = await mDBffi.openDatabase(mPath);
    createDB();
    return this;
  }

  @override
  Future<T> getItem<T>(List<String> aID) async {
    super.getItem(aID);
    var val =
        await get(['uuid', 'name', 'date'], aWhere: 'id = ?', aWhereArgs: aID);
    return val.first as T;
  }

  @override
  Future createDB() async {
    super.createDB();
    mDB!.execute('CREATE TABLE IF NOT EXISTS $mTableName'
        '(id INTEGER PRIMARY KEY AUTOINCREMENT,'
        'uuid REAL NOT NULL,'
        'name TEXT NOT NULL,'
        'date INTEGER'
        ')');
  }

  @override
  Future update<T, B>(List<B> aID, DBData aValues) async {
    super.update(aID, aValues);
    aValues["id"] = aID;
    await mDB!.update(mTableName, aValues);
  }

  // Get DB count
  Future<int> getTotalItemCount() async {
    return Sqflite.firstIntValue(
            await mDB!.rawQuery("SELECT COUNT(*) FROM $mTableName")) ??
        0;
  }

  static Future<DeviceDB> getInstance() async {
    String path = join(await _OSABPaths.path, "db.sql");
    return DeviceDB(mPath: path, mTableName: "DEV").openDB();
  }
}

typedef DBData = Map<String, Object?>;
