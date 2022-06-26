import 'package:flutter/material.dart';
import 'package:osab/material/pages/settings/profile.dart';
import 'package:osab/material/pages/settings/device.dart';

class AndroidSettings extends StatelessWidget {
  const AndroidSettings({super.key});

  @override
  Widget build(BuildContext context) {
    final List<Widget> settingsWidgets = <Widget>[
      Card(
        child: ListTile(
          leading: const Icon(Icons.person),
          subtitle: const Text("Profile"),
          trailing: const Icon(Icons.arrow_forward),
          onTap: () {
            Navigator.push(
                context,
                MaterialPageRoute(
                    builder: ((context) => const AndroidSettingsProfile())));
          },
        ),
      ),
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
    return Column(children: <Widget>[
      const Expanded(
          flex: 1,
          child: Card(
            child: SizedBox.expand(
              child: Text("Lol"),
            ),
          )),
      Expanded(
          flex: 2,
          child: ListView(
            children: settingsWidgets,
          )),
    ]);
  }
}
