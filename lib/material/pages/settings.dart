import 'package:flutter/material.dart';
// import 'package:osab/material/pages/settings/profile.dart';
import 'package:osab/material/pages/settings/device.dart';

class AndroidSettings extends StatelessWidget {
  const AndroidSettings({super.key});

  @override
  Widget build(BuildContext context) {
    final List<Widget> settingsWidgets = <Widget>[
      Card(
          child: ListTile(
              leading: const Icon(Icons.phone),
              subtitle: const Text("Device"),
              trailing: const Icon(Icons.arrow_forward),
              onTap: () {
                Navigator.push(
                    context,
                    MaterialPageRoute(
                        builder: ((context) => const AndroidSettingsDevice())));
              })),
    ];
    return Scaffold(
      body: Column(children: <Widget>[
        Expanded(
            flex: 2,
            child: ListView(
              children: settingsWidgets,
            )),
      ]),
    );
  }
}
