RabbitHole_B1F_3R_MapScripts::
	.byte 0

RabbitHole_B1F_3R_EventScript_WarmRock:: @ Rock
	msgbox RabbitHole_B1F_3R_Text_WarmRock, MSGBOX_SIGN
	random 4
	compare VAR_RESULT, 0
	goto_if_eq RabbitHole_B1F_3R_EventScript_Larvesta
	end

RabbitHole_B1F_3R_EventScript_Larvesta:: @Rock
	msgbox RabbitHole_B1F_3R_Text_Larvesta
	setwildbattle SPECIES_LARVESTA, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	end

RabbitHole_B1F_3R_Text_WarmRock: @ Rock
	.string "This rock is warm to the touch.$"

RabbitHole_B1F_3R_Text_Larvesta: @Rock
	.string "The rock is glowing like mad!$"
