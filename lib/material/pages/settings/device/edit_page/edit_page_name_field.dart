import 'package:flutter/material.dart';
import 'package:osab/db/actions.dart';

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
              : "";
          widget.controller.text = name;
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
    var data = await DBActions.getDevice(id);
    if (data == null || data.name == "null") {
      return "";
    }
    return data.name;
  }
}
