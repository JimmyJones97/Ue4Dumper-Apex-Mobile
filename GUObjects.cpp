#include "includes.h"

int32 GetObjectCount() {
    return Read<int32>(getRealOffset(Offsets::GUObjectArray) +
        Offsets::FUObjectArrayToTUObjectArray +
        Offsets::TUObjectArrayToNumElements);
}

kaddr GetUObjectFromID(uint32 index) {
    kaddr TUObjectArray = getPtr(
        getRealOffset(Offsets::GUObjectArray) + Offsets::FUObjectArrayToTUObjectArray);
    kaddr Chunk = getPtr(TUObjectArray + ((index / 0x10000) * Offsets::PointerSize));

    return getPtr(Chunk + Offsets::FUObjectItemPad + ((index % 0x10000) * Offsets::FUObjectItemSize));
}

void DumpObjects(string out) {
    uint32 count = 0;
    ofstream obj(out + "Objects.txt", ofstream::out);
    if (obj.is_open()) {
        cout << "Dumping Objects List: " << GetObjectCount() << endl;
        clock_t begin = clock();
        for (int32 i = 0; i < GetObjectCount(); i++) {
            kaddr uobj = GetUObjectFromID(i);
            if (UObject::isValid(uobj)) {
                if (Settings::isVerbose) {
                    cout << setbase(10) << "[" << i << "]: " << UObject::getName(uobj) << endl;
                }
                obj << setbase(10) << "[" << i << "]:" << endl;
                obj << "Name: " << UObject::getName(uobj).c_str() << endl;
                obj << "Class: " << UObject::getClassName(uobj).c_str() << endl;
                obj << "ObjectPtr: 0x" << setbase(16) << uobj << endl;
                obj << "ClassPtr: 0x" << setbase(16) << UObject::getClass(uobj) << endl;
                obj << endl;
                count++;
            }
        }
        obj.close();
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << count << " Valid Objects Dumped in " << elapsed_secs << "S" << endl;
    }
}