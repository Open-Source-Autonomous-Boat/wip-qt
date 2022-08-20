import 'package:flutter/material.dart';
import 'package:osab/db/actions.dart';
import 'package:osab/db/db.dart';
import 'package:osab/material/pages/settings/device/edit_page.dart';

class DeviceGetCard extends StatefulWidget {
  final int mID;

  final BoxConstraints constraints;
  final Function(BuildContext context) callback;
  const DeviceGetCard(
      {Key? key,
      required this.mID,
      required this.constraints,
      required this.callback})
      : super(key: key);

  @override
  State<StatefulWidget> createState() => _DeviceGetCard();
}

class _DeviceGetCard extends State<DeviceGetCard> {
  late final int mID = widget.mID;
  late final BoxConstraints constraints = widget.constraints;

  late final Future<DeviceDataValues?> mDeviceData;

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
        future: mDeviceData,
        builder:
            ((BuildContext context, AsyncSnapshot<DeviceDataValues?> snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return Card(
                child: GridTile(
                    header: ClipRRect(
                        borderRadius: BorderRadius.circular(8),
                        child: GridTileBar(
                            title: const Text("Waiting..."),
                            backgroundColor: Theme.of(context)
                                .colorScheme
                                .secondaryContainer)),
                    child:
                        const Center(child: Icon(Icons.file_copy_outlined))));
          } else if (snapshot.hasData &&
              snapshot.connectionState == ConnectionState.done) {
            final DeviceDataValues data = snapshot.data!;
            final ElevatedButton editButton = ElevatedButton.icon(
                onPressed: () {
                  EditPage.showDialog(context, mID, callback: widget.callback);
                },
                icon: const Icon(Icons.edit),
                label: const Text("Edit"));
            return Card(
                child: GridTile(
              header: ClipRRect(
                borderRadius: BorderRadius.circular(8),
                child: GridTileBar(
                  title: Text(data.name),
                  backgroundColor:
                      Theme.of(context).colorScheme.primaryContainer,
                ),
              ),
              footer: editButton,
              child: const Center(child: Icon(Icons.directions_boat)),
            ));
          } else {
            return GridTile(
              header: ClipRRect(
                borderRadius: BorderRadius.circular(0),
                child: GridTileBar(
                  title: const Text("NULL DEVICE"),
                  backgroundColor: Theme.of(context).colorScheme.errorContainer,
                ),
              ),
              child: const Center(child: Icon(Icons.error)),
            );
          }
        }));
  }

  @override
  void initState() {
    super.initState();
    mDeviceData = _getData();
  }

  Future<DeviceDataValues?> _getData() async {
    return await DBActions.getDevice(mID.toString());
  }
}
