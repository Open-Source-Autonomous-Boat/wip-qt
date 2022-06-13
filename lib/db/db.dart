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

  Future<DBClass> openDB() async {
    mDB = await mDBffi.openDatabase(mPath);
    createDB();
    return this;
  }

  Future<bool> closeDB() async {
    if (mDB!.isOpen) {
      mDB!.close();
    }
    return true;
  }

  Future<List<Object>> get(List<String> aColumn,
      {String? aWhere, List<Object>? aWhereArgs});

  Future<T?> getValue<T>(List<String> aWhere);

  Future set<T>(String aName, T aValue);

  Future rm(String aName, {String? aWhere, List<Object>? aWhereArgs}) async {
    await mDB!.delete(mTableName, where: aWhere, whereArgs: aWhereArgs);
  }

  Future createDB();

  Future deleteDB() async {
    await mDB!.delete(mTableName);
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
  Future createDB() {
    // TODO: implement createDB
    throw UnimplementedError();
  }

  @override
  Future<List<Object>> get(List<String> aColumn,
      {String? aWhere, List<Object>? aWhereArgs}) {
    // TODO: implement get
    throw UnimplementedError();
  }

  @override
  Future<T?> getValue<T>(List<String> aWhere) {
    // TODO: implement getValue
    throw UnimplementedError();
  }

  @override
  Future set<T>(String aName, T aValue) {
    // TODO: implement set
    throw UnimplementedError();
  }
}

class StaticStore {
  static Map<String, Object> dbStored = {};
}
