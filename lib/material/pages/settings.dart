import 'package:flutter/material.dart';
import 'package:osab/material/pages/settings/profile.dart';

class AndroidSettings extends StatelessWidget {
  const AndroidSettings({super.key});
  @override
  Widget build(BuildContext context) {
    final List<Widget> settingsWidgets = <Widget>[
      Card(
        child: ListTile(
          leading: const Text("Profile"),
          trailing: const Icon(Icons.arrow_forward),
          onTap: () {
            Navigator.push(
                context,
                MaterialPageRoute(
                    builder: ((context) => const AndroidSettingsProfile())));
          },
        ),
      ),
    ];
    return Column(children: [
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