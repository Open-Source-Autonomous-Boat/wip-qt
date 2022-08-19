import 'package:flutter/material.dart';
import 'package:osab/db/db.dart';
import 'package:osab/material/pages/settings/device/edit_page.dart';
import './device/device_card.dart';

class AndroidSettingsDevice extends StatefulWidget {
  const AndroidSettingsDevice({super.key});

  @override
  State<StatefulWidget> createState() => _AndroidSettingsDevice();
}

class _AndroidSettingsDevice extends State<AndroidSettingsDevice> {
  late Future<int> mCount;
  List<Widget> children = [];

  void callback(BuildContext context) {
    children = [];
    setState(() {
      mCount = _getCount();
    });
  }

  @override
  void initState() {
    super.initState();
    mCount = _getCount();
  }

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(
        builder: (BuildContext context, BoxConstraints constraints) {
      return Scaffold(
          appBar: AppBar(
            title: const Text("Device"),
            titleTextStyle: const TextStyle(fontWeight: FontWeight.bold),
          ),
          body: FutureBuilder(
              future: mCount,
              builder: ((context, snapshot) {
              children = [];
                const Widget errorText = Center(
                  child: Text(
                    "No Device Found",
                    textAlign: TextAlign.center,
                  ),
                );
                if (snapshot.hasData &&
                    snapshot.connectionState == ConnectionState.done) {
                  int data = snapshot.data as int;
                  for (int i = 0; i < data; ++i) {
                    children.add(DeviceGetCard(
                      mID: i,
                      constraints: constraints,
                      callback: callback,
                    ));
                  }
                  return (data > 0)
                      ? GridView.count(
                          padding: const EdgeInsets.all(5),
                          crossAxisCount: (constraints.maxWidth ~/ 250),
                          children: children,
                        )
                      : errorText;
                } else {
                  return errorText;
                }
              })),
          floatingActionButton: FutureBuilder(
              future: mCount,
              builder: ((BuildContext context, AsyncSnapshot<int> snapshot) {
                if (snapshot.hasData &&
                    snapshot.connectionState == ConnectionState.done) {
                  int data = snapshot.data!;
                  return FloatingActionButton(
                    onPressed: () {
                      EditPage.showDialog(context, data,
                          firstTime: true, callback: callback);
                    },
                    child: const Icon(Icons.add),
                  );
                }
                return FloatingActionButton(
                  onPressed: () {},
                  backgroundColor: Colors.red,
                  child: const Text("ERROR!"),
                );
              })));
    });
  }

  Future<int> _getCount() async {
    //DeviceDB db = await DeviceDB.getInstance();
    //return await db.getTotalItemCount();
    DBClass db = await DBInstances.devices();
    return await db.getCount();
  }
}
