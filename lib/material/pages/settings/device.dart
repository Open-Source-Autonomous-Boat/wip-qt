import 'package:flutter/material.dart';
import 'package:osab/material/styles/text.dart';

class AndroidSettingsDevice extends StatelessWidget {
  const AndroidSettingsDevice({super.key});

  @override
  Widget build(BuildContext context) => Scaffold(
        appBar: AppBar(
          title: const Text("Device"),
          titleTextStyle: const TextStyle(fontWeight: FontWeight.bold)
        ),
        body: ListView(
          children: <Widget>[
            TextStyles.sectionTitle("Device", context)
          ],
        )
      );
}
