import 'package:flutter/material.dart';
import 'package:osab/map/map.dart';
import 'package:osab/material/pages/dashboard.dart';
import 'package:osab/material/pages/settings.dart';

class AndroidHome extends StatefulWidget {
  const AndroidHome({super.key});

  @override
  State<StatefulWidget> createState() => _AndroidHome();
}

class _AndroidHome extends State<AndroidHome> {
  int mPage = 0;

  final List<Widget> pages = const <Widget>[
    AndroidDashBoard(),
    OSABMap(),
    AndroidSettings()
  ];

  void mCallBack(int aIndex) {
    setState(() {
      mPage = aIndex;
    });
  }

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(builder: (context, container) {
      return Scaffold(
          appBar: AppBar(
            title: const Text("OSAB - Watercraft Interface"),
          ),
          bottomNavigationBar: (container.maxWidth < 600)
              ? NavigationBar(
                  selectedIndex: mPage,
                  destinations: const [
                    NavigationDestination(
                      icon: Icon(Icons.home),
                      label: "Home",
                    ),
                    NavigationDestination(icon: Icon(Icons.map), label: "Map"),
                    NavigationDestination(
                        icon: Icon(Icons.settings), label: "Settings")
                  ],
                  onDestinationSelected: (int aSelIndex) =>
                      mCallBack(aSelIndex))
              : null,
          body: (container.maxWidth < 600)
              ? pages[mPage]
              : Row(
                  children: [
                    NavigationRail(
                        destinations: const [
                          NavigationRailDestination(
                              icon: Icon(Icons.home), label: Text("lol")),
                          NavigationRailDestination(
                              icon: Icon(Icons.map), label: Text("Map")),
                          NavigationRailDestination(
                              icon: Icon(Icons.settings),
                              label: Text("Settings"))
                        ],
                        onDestinationSelected: (aSelIndex) =>
                            mCallBack(aSelIndex),
                        selectedIndex: mPage),
                    Expanded(child: pages[mPage])
                  ],
                ));
    });
  }
}
