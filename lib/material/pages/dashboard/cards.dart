import 'package:flutter/material.dart';
import 'package:osab/db/db.dart';
import 'package:osab/material/styles/text.dart';
import 'package:uuid/uuid.dart';
import 'dart:async';

class _LocationCard extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Card(
        child: Column(children: [
      ListTile(
        leading: const Icon(Icons.location_city),
        title: TextStyles.cardText("Location"),
        subtitle: const Text("Washington DC"),
      ),
      ButtonBar(
        children: [
          TextButton(onPressed: (() => {}), child: const Text("Open Settings"))
        ],
      )
    ]));
  }
}

class _DeviceCard extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _DeviceCardState();
}

class _DeviceCardState extends State<_DeviceCard> {
  late Future<String> mName;
  var mDeviceQuery = ["Change Name", "Set Name"];
  int mDeviceIndex = 0;
  final TextEditingController mTextCtrl = TextEditingController();

  @override
  void initState() {
    super.initState();
    mName = _getDeviceName();
  }

  @override
  void dispose() {
    mTextCtrl.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Card(
        child: Column(children: [
      ExpansionTile(
        leading: const Icon(Icons.devices),
        title: TextStyles.cardText("Device"),
        subtitle: const Text("CONNECTED"),
        children: [
          FutureBuilder(
              future: mName,
              builder: ((context, AsyncSnapshot<String> snapshot) {
                if (snapshot.hasData) {
                  String name = snapshot.data!;
                  var deviceNameList = [
                    Text(name),
                    TextField(
                      controller: mTextCtrl,
                      decoration: InputDecoration(
                          label: const Text("Set Name"), hintText: name),
                    )
                  ];
                  return ListTile(
                    title: const Text("Device Name"),
                    subtitle: deviceNameList[mDeviceIndex],
                    trailing: TextButton(
                      child: Text(mDeviceQuery[mDeviceIndex]),
                      onPressed: () {
                        setState(() {
                          if (mDeviceIndex > 0) {
                            _setDeviceName(mTextCtrl.text);
                            mName = _getDeviceName();
                          }
                          mDeviceIndex = (mDeviceIndex == 0) ? 1 : 0;
                        });
                      },
                    ),
                  );
                } else {
                  return const ListTile(
                    title: Text("Device Name"),
                    subtitle: Text("FAILED TO GET NAME"),
                  );
                }
              })),
          ListTile(
            title: const Text("UUID"),
            subtitle: Text(const Uuid().v1()),
          ),
          const ListTile(
            title: Text("Date Added"),
          )
        ],
      ),
      ButtonBar(
        children: [
          TextButton(onPressed: (() => {}), child: const Text("Disconnect"))
        ],
      )
    ]));
  }

  Future<String> _getDeviceName() async {
    OSABDB db = await OSABDB.mainDB();
    return await db.getValue(['devname']);
  }

  void _setDeviceName(aName) {
    OSABDB.mainDB().then((value) {
      value.set<String>("devname", aName);
    });
  }
}

class _GreetingCard extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _GreetingCardState();
}

class _GreetingCardState extends State<_GreetingCard> {
  late final Future<String> mName;

  @override
  void initState() {
    super.initState();
    mName = _getUserName();
  }

  @override
  Widget build(BuildContext context) {
    return Expanded(
      flex: 1,
      child: FutureBuilder<String>(
        future: mName,
        builder: (context, snapshot) {
          if (snapshot.hasData) {
            return Card(
              child: SizedBox.expand(
                  child: Stack(children: [
                Center(
                    child: Image.network(
                  'https://upload.wikimedia.org/wikipedia/commons/5/58/Blue_ocean_wave_(Unsplash).jpg',
                  fit: BoxFit.fill,
                )),
                Center(
                  child: TextStyles.cardText(snapshot.data!),
                )
              ])),
            );
          } else {
            return Card(
              child: SizedBox.expand(
                child: TextStyles.cardText("FAILED TO GET USER NAME!"),
              ),
            );
          }
        },
      ),
    );
  }

  static Future<String> _getUserName() async {
    // Hopefully doesn't cause issues :)
    OSABDB db = await OSABDB.mainDB();
    return await db.getValue(['name']);
  }
}

class DashBoardCards {
  static var list = [_DeviceCard(), _LocationCard()];
  static Widget greetingCard() => _GreetingCard();
}
