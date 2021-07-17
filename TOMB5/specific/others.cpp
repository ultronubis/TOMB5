#include "../tomb5/pch.h"
#include "others.h"
#include "function_stubs.h"

/*the home of all the functions that I don't where else to go with :)*/

void aLoadRoomStream()
{
	ROOM_INFO* room_data;
	int length, num_rooms, size;
	char* data;

	length = *(long*)FileData;
	FileData += sizeof(long);
	num_rooms = *(long*)FileData;
	FileData += sizeof(long);
	room = (ROOM_INFO*)game_malloc(num_rooms * sizeof(ROOM_INFO), 0);
	room_data = room;

	for (int i = 0; i < num_rooms; i++)
	{
		FileData += sizeof(long);
		size = *(long*)FileData;
		FileData += sizeof(long);
		data = (char*)game_malloc(size, 0);
		memcpy(data, FileData, size);
		aFixUpRoom(room_data, data);
		FileData += size;
		room_data++;
	}

	number_rooms = num_rooms;
}

void inject_others(bool replace)
{
	INJECT(0x004916C0, aLoadRoomStream, replace);
}
