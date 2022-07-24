import 'package:flutter/material.dart';
import 'package:osab/material/styles/text.dart';

class _ProfileNameClass extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _ProfileNameClassState();
}

class _ProfileNameClassState extends State<_ProfileNameClass> {
  @override
  Widget build(BuildContext context) => ListTile(
        leading: const Icon(Icons.person),
        subtitle: const TextField(
          decoration: InputDecoration(
              border: OutlineInputBorder(), label: Text("Profile Name")),
        ),
        trailing: TextButton(
          child: const Text("Set"),
          onPressed: () {},
        ),
      );
}

class _OrganizationNameClass extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _OrganizationNameClassState();
}

class _OrganizationNameClassState extends State<_OrganizationNameClass> {
  @override
  Widget build(BuildContext context) => ListTile(
        leading: const Icon(Icons.people),
        subtitle: const TextField(
          decoration: InputDecoration(
              border: OutlineInputBorder(), label: Text("Organization Name")),
        ),
        trailing: TextButton(
          child: const Text("Set"),
          onPressed: () {},
        ),
      );
}

class AndroidSettingsProfile extends StatefulWidget {
  const AndroidSettingsProfile({super.key});
  @override
  State<StatefulWidget> createState() => _AndroidSettingsProfile();
}

class _AndroidSettingsProfile extends State<AndroidSettingsProfile> {
  _AndroidSettingsProfile();

  @override
  Widget build(BuildContext context) => Scaffold(
        appBar: AppBar(
          title: const Text("Profile"),
          titleTextStyle: const TextStyle(fontWeight: FontWeight.bold),
        ),
        body: ListView(
          children: [
            TextStyles.sectionTitle("Personal Information", context),
            _ProfileNameClass(),
            const Divider(),
            TextStyles.sectionTitle("Organizational Information", context),
            _OrganizationNameClass(),
          ],
        ),
      );
}
