import 'package:flutter/material.dart';
import 'package:osab/map/map.dart';
import 'package:osab/material/pages/dashboard.dart';

class AndroidHome extends StatefulWidget {
  const AndroidHome({super.key});

  @override
  State<StatefulWidget> createState() => _AndroidHome();
}

class _AndroidHome extends State<AndroidHome> {
  int mPage = 0;

  void mCallBack(int aIndex) {
    setState(() {
      mPage = aIndex;
    });
  }

  Widget mobileHome() {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Test"),
      ),
      bottomNavigationBar: NavigationBar(
          selectedIndex: mPage,
          destinations: const [
            NavigationDestination(
              icon: Icon(Icons.home),
              label: "Home",
            ),
            NavigationDestination(icon: Icon(Icons.map), label: "Map"),
            NavigationDestination(icon: Icon(Icons.settings), label: "Settings")
          ],
          onDestinationSelected: (int aSelIndex) => mCallBack(aSelIndex)),
      body: [
        const AndroidDashBoard(),
        const OSABMap(),
        const Text("Settings")
      ][mPage],
    );
  }

  Widget desktopHome() {
    return Scaffold(
        appBar: AppBar(
          title: const Text("Test"),
        ),
        body: Row(
          children: [
            NavigationRail(
                destinations: const [
                  NavigationRailDestination(
                      icon: Icon(Icons.home), label: Text("lol")),
                  NavigationRailDestination(
                      icon: Icon(Icons.map), label: Text("Map")),
                  NavigationRailDestination(
                      icon: Icon(Icons.settings), label: Text("Settings"))
                ],
                onDestinationSelected: (aSelIndex) => mCallBack(aSelIndex),
                selectedIndex: mPage),
            Expanded(
                child: const [
              AndroidDashBoard(),
              OSABMap(),
              Text("Settings")
            ][mPage])
          ],
        ));
  }

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(builder: (context, container) {
      if (container.maxWidth < 600) {
        return mobileHome();
      } else {
        return desktopHome();
      }
    });
  }
}
