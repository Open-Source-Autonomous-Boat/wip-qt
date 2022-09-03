import 'dart:async';
import 'dart:io';

import 'package:flutter/material.dart';
import 'package:osab/material/home.dart';
import 'package:sqflite_common_ffi/sqflite_ffi.dart';

Future<void> main(List<String> args) async {
  WidgetsFlutterBinding.ensureInitialized();
  if (Platform.isMacOS || Platform.isLinux || Platform.isWindows) {
    sqfliteFfiInit();
  }
  runApp(const AndroidApp());
}

class AndroidApp extends StatelessWidget {
  const AndroidApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(useMaterial3: true, brightness: Brightness.light),
      darkTheme: ThemeData(useMaterial3: true, brightness: Brightness.dark),
      themeMode: ThemeMode.system,
      debugShowCheckedModeBanner: false,
      title: "Watercraft Interface Program - Flutter",
      home: const Scaffold(body: AndroidHome()),
    );
  }
}
