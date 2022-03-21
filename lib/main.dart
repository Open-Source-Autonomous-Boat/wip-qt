import 'dart:io';
import 'dart:async';

import 'package:adwaita_icons/adwaita_icons.dart';
import 'package:flutter/material.dart';
import 'package:fluent_ui/fluent_ui.dart' as fluent;
import 'package:flutter/cupertino.dart';
import 'package:macos_ui/macos_ui.dart';
import 'package:libadwaita/libadwaita.dart';
import 'package:adwaita/adwaita.dart';
import 'package:system_theme/system_theme.dart';
import 'package:flutter_acrylic/flutter_acrylic.dart' as fl_acr;

import 'ui/dashboard.dart';

void main(List<String> aArgs) async {
  WidgetsFlutterBinding.ensureInitialized();
  await SystemTheme.accentInstance.load();
  if (Platform.isWindows || Platform.isMacOS) fl_acr.Window.initialize();
  runApp(OSAB());
}

class OSAB extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    return _OSABState();
  }
}

class _OSABState extends State<OSAB> {
  int winIndex = 0;

  @override
  Widget build(BuildContext aContext) {
    if (Platform.isWindows) {
      return fluent.FluentApp(
        title: 'WINDOWS | OSAB',
        home: this.WindowsLayout(),
        theme: fluent.ThemeData(
            accentColor: SystemTheme.accentInstance.accent.toAccentColor()),
        darkTheme: fluent.ThemeData(
            accentColor: SystemTheme.accentInstance.accent.toAccentColor(),
            brightness: fluent.Brightness.dark),
      );
    } else if (Platform.isMacOS) {
      return const MacosApp();
    } else if (Platform.isLinux) {
      return MaterialApp(
          title: 'I run Linux',
          theme: AdwaitaThemeData.light(),
          darkTheme: AdwaitaThemeData.dark(),
          home: LinuxLayout());
    } else {
      return const MaterialApp();
    }
  }

  // Layout
  fluent.NavigationView WindowsLayout() {
    return fluent.NavigationView(
      appBar: const fluent.NavigationAppBar(title: Text('I like windows owo')),
      pane: fluent.NavigationPane(
          selected: winIndex,
          onChanged: (aIndex) => {
                setState(() => {winIndex = aIndex})
              },
          displayMode: fluent.PaneDisplayMode.auto,
          items: OSABPaneItems.WindowsPane()),
      content: OSABDashboard(
        aIndex: winIndex,
      ),
    );
  }

  Scaffold AndroidLayout() {
    return Scaffold(
      appBar: AppBar(title: const Text('I like Android')),
    );
  }

  AdwScaffold LinuxLayout() {
    return AdwScaffold(
        headerbar: (_) => AdwHeaderBar(
              title: const Text('LINUX | OSAB'),
            ),
        body: const Center(
          child: const Text('I love Linux'),
        ));
  }
}
