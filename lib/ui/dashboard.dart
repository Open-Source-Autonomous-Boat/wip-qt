import 'dart:io';

import 'package:fluent_ui/fluent_ui.dart' as fluent;
import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';

class OSABDashboard extends StatelessWidget {
  int winIndex = 0;

  OSABDashboard({Key? key, int? aIndex}) : super(key: key) {
    if (aIndex != null) {
      winIndex = aIndex;
    }
  }

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    if (Platform.isWindows) {
      return fluent.NavigationBody(index: winIndex, children: [
        fluent.ScaffoldPage.scrollable(
          children: [
            Row(
              crossAxisAlignment: fluent.CrossAxisAlignment.start,
              children: [
                fluent.Expanded(
                    child: fluent.TextBox(
                  header: 'Cum',
                ))
              ],
            ),
            fluent.TextButton(
              child: fluent.Text('Lol'),
              onPressed: () => {exit(0)},
            )
          ],
        )
      ]);
    } else {
      throw UnimplementedError('Under construction (tm)');
    }
  }
}

class OSABPaneItems {
  OSABPaneItems() {}
  static List<fluent.NavigationPaneItem> WindowsPane() {
    return [
      fluent.PaneItem(
          icon: const fluent.Icon(fluent.FluentIcons.home),
          title: const Text('Dashboard')),
      fluent.PaneItem(
          icon: const fluent.Icon(fluent.FluentIcons.map_layers),
          title: const Text('Map'))
    ];
  }
}
