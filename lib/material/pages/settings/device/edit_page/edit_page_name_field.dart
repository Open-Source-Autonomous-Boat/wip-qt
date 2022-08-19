import 'package:flutter/material.dart';
import 'package:osab/db/db.dart';

class EditPageNameField extends StatefulWidget {
  const EditPageNameField(
      {super.key, required this.id, required this.controller});
  @override
  State<StatefulWidget> createState() => _EditPageNameField();


  String getText() => controller.text;

  final TextEditingController controller;

  final String id;
}

class _EditPageNameField extends State<EditPageNameField> {
  late Future<String> mName;

  @override
  void initState() {
    super.initState();
    mName = _getName();
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
        future: mName,
        builder: (context, snapshot) {
          String name = (snapshot.hasData &&
                  snapshot.connectionState == ConnectionState.done)
              ? snapshot.data.toString()
              : "ERROR!";
          return ListTile(
            leading: const Icon(Icons.edit),
            subtitle: TextField(
              controller: widget.controller,
              decoration: InputDecoration(
                  border: const OutlineInputBorder(),
                  labelText: "Name",
                  hintText: name),
            ),
          );
        });
  }

  Future<String> _getName() async {
    String id = widget.id;
    var data =
        DeviceData().from(await (await DBInstances.devices()).getItem(id));
    if (data.isEmpty || data.first.name == "null") {
      return "";
    }
    return data.first.name;
  }
}
