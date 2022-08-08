#include "includes.h"
namespace Offsets {
    //Global
    kaddr Base;
    kaddr EndBase;
    kaddr GWorld;
    kaddr GNames;
    kaddr GUObjectArray;
    kaddr PointerSize;
    kaddr FUObjectItemPad;
    kaddr FUObjectItemSize;

    //---------SDK-----------//
    //---------4.23+---------//
    //Class: FNamePool
    kaddr FNameStride;
    kaddr GNamesToFNamePool;//NamePoolData, alignas(FNamePool)
    kaddr FNamePoolToCurrentBlock;
    kaddr FNamePoolToCurrentByteCursor;
    kaddr FNamePoolToBlocks;
    //Class: FNameEntry
    kaddr FNameEntryToLenBit;
    kaddr FNameEntryToString;
    //Class: UStruct
    kaddr UStructToChildProperties;
    //Class: FField
    kaddr FFieldToClass;
    kaddr FFieldToNext;
    kaddr FFieldToName;
    //---------4.18+---------//
    //Class: FNameEntry
    kaddr FNameEntryToNameString;
    //-----------------------//
    //Class: FUObjectArray
    kaddr FUObjectArrayToTUObjectArray;
    //Class: TUObjectArray
    kaddr TUObjectArrayToNumElements;
    //Class: UObject
    kaddr UObjectToInternalIndex;
    kaddr UObjectToClassPrivate;
    kaddr UObjectToFNameIndex;
    kaddr UObjectToOuterPrivate;
    //Class: UField
    kaddr UFieldToNext;
    //Class: UStruct
    kaddr UStructToSuperStruct;
    kaddr UStructToChildren;
    //Class: UFunction
    kaddr UFunctionToFunctionFlags;
    kaddr UFunctionToFunc;
    //Class: UProperty
    kaddr UPropertyToElementSize;
    kaddr UPropertyToPropertyFlags;
    kaddr UPropertyToOffsetInternal;
    //Class: UBoolProperty
    kaddr UBoolPropertyToFieldSize;
    kaddr UBoolPropertyToByteOffset;
    kaddr UBoolPropertyToByteMask;
    kaddr UBoolPropertyToFieldMask;
    //Class: UObjectProperty
    kaddr UObjectPropertyToPropertyClass;
    //Class: UClassProperty
    kaddr UClassPropertyToMetaClass;
    //Class: UInterfaceProperty
    kaddr UInterfacePropertyToInterfaceClass;
    //Class: UArrayProperty
    kaddr UArrayPropertyToInnerProperty;
    //Class: UMapProperty
    kaddr UMapPropertyToKeyProp;
    kaddr UMapPropertyToValueProp;
    //Class: USetProperty
    kaddr USetPropertyToElementProp;
    //Class: UStructProperty
    kaddr UStructPropertyToStruct;
    //Class: UWorld
    kaddr UWorldToPersistentLevel;
    //Class: ULevel
    kaddr ULevelToAActors;
    kaddr ULevelToAActorsCount;

    void initOffsets_32() {
        //Global
        PointerSize = 0x4;
        FUObjectItemPad = 0x0;
        FUObjectItemSize = 0x10;

        //---------SDK-----------
        //Class: FNameEntry
        FNameEntryToNameString = 0x8;
        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x8;
        //Class: UObject
        UObjectToInternalIndex = 0x8;
        UObjectToClassPrivate = 0xC;
        UObjectToFNameIndex = 0x10;
        UObjectToOuterPrivate = 0x18;
        //Class: UField
        UFieldToNext = 0x1C;
        //Class: UStruct
        UStructToSuperStruct = 0x28;
        UStructToChildren = 0x2c;
        //Class: UFunction
        UFunctionToFunctionFlags = 0x58;
        UFunctionToFunc = 0x98;
        //Class: UProperty
        UPropertyToElementSize = 0x24;
        UPropertyToPropertyFlags = 0x28;
        UPropertyToOffsetInternal = 0x34;
        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x50;
        UBoolPropertyToByteOffset = 0x51;
        UBoolPropertyToByteMask = 0x52;
        UBoolPropertyToFieldMask = 0x53;
        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x50;
        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x54;
        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x54;
        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x50;
        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x50;
        UMapPropertyToValueProp = 0x54;
        //Class: USetProperty
        USetPropertyToElementProp = 0x50;
        //Class: UStructProperty
        UStructPropertyToStruct = 0x50;
        //Class: UWorld
        UWorldToPersistentLevel = 0x20;
        //Class: ULevel
        ULevelToAActors = 0x70;
        ULevelToAActorsCount = 0x74;
    }
    void patchUE423_32() {
        //Class: FNamePool
        FNameStride = 0x2;
        GNamesToFNamePool = 0x30;
        FNamePoolToCurrentBlock = 0x4;
        FNamePoolToCurrentByteCursor = 0x8;
        FNamePoolToBlocks = 0x0;
        //Class: FNameEntry
        FNameEntryToLenBit = 6;
        FNameEntryToString = 0x2;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x10;
        //Class: UStruct
        UStructToChildProperties = 0x30;
        //Class: FField
        FFieldToClass = 0x4;
        FFieldToNext = 0x10;
        FFieldToName = 0x14;
    }
}

