#pragma once
#include "../global/vars.h"

void inject_door(bool replace);


void ShutThatDoor(DOORPOS_DATA* d, DOOR_DATA* dd);
void OpenThatDoor(DOORPOS_DATA* d, DOOR_DATA* dd);
void DoorControl(short item_number);
void DoorCollision(short item_num, ITEM_INFO* l, COLL_INFO* coll);
void PushPullKickDoorControl(short item_number);
void PushPullKickDoorCollision(short item_num, ITEM_INFO* l, COLL_INFO* coll);
void DoubleDoorCollision(short item_num, ITEM_INFO* l, COLL_INFO* coll);
void UnderwaterDoorCollision(short item_num, ITEM_INFO* l, COLL_INFO* coll);
void SequenceDoorControl(short item_number);
//void ProcessClosedDoors();//no

