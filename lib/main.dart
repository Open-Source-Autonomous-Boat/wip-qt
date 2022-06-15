import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart' as material;
import 'package:osab/material/home.dart';
import 'dart:async';

import 'package:osab/meta/navigation.dart';
import 'package:sqflite_common_ffi/sqflite_ffi.dart';

Future<void> main(List<String> args) async {
  if (Platform.isMacOS || Platform.isLinux || Platform.isWindows) {
    sqfliteFfiInit();
  }
  switch (defaultTargetPlatform) {
    case (TargetPlatform.iOS):
      material.runApp(const AndroidApp());
      break;
    case (TargetPlatform.windows):
      material.runApp(const AndroidApp());
      break;
    case (TargetPlatform.linux):
      material.runApp(const AndroidApp());
      break;
    case (TargetPlatform.fuchsia):
    case (TargetPlatform.android):
    default:
      material.runApp(const AndroidApp());
  }
}

class AndroidApp extends material.StatefulWidget {
  const AndroidApp({super.key});
  @override
  material.State<material.StatefulWidget> createState() {
    return _AndroidApp();
  }
}

class _AndroidApp extends material.State<AndroidApp> {
  @override
  material.Widget build(material.BuildContext context) {
    return material.MaterialApp(
      navigatorKey: GlobalNavigation.globalNavigation,
      theme: material.ThemeData(useMaterial3: true),
      home: const material.Scaffold(body: AndroidHome()),
    );
  }
}
