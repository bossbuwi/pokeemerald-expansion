PetalburgWoodsSE_MapScripts::
	.byte 0

PetalburgWoodsSE_EventScript_Sign1:: @ SignOnEntrance
	msgbox PetalburgWoodsSE_Text_Sign1, MSGBOX_SIGN
	random 4
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoodsSE_Event_Cascoon
	compare VAR_RESULT, 2
	goto_if_eq PetalburgWoodsSE_Event_Silcoon
	end

PetalburgWoodsSE_Event_Cascoon:: @ SignOnEntrance
	setwildbattle SPECIES_CASCOON, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	end

PetalburgWoodsSE_Event_Silcoon:: @ SignOnEntrance
	setwildbattle SPECIES_SILCOON, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	end	

PetalburgWoodsSE_Text_Sign1: @ SignOnEntrance
	.string "This sign is made from a wood that\n"
	.string "attracts native bugs.$"

PetalburgWoodsSE_EventScript_PondRock:: @ PondRock
	msgbox PetalburgWoodsSE_Text_PondRock, MSGBOX_SIGN
	goto_if_set FLAG_UNUSED_0x264, PetalburgWoodsSE_EventScript_MespritAlreadyCaught
	goto_if_set FLAG_UNUSED_0x935, PetalburgWoodsSE_EventScript_MespritAlreadyCaught
	goto PetalburgWoodsSE_EventScript_Mesprit
	end

PetalburgWoodsSE_EventScript_Mesprit:: @ PondRock
	msgbox PetalburgWoodsSE_Text_Mesprit, MSGBOX_SIGN
	setwildbattle SPECIES_MESPRIT, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq PetalburgWoodsSE_EventScript_MespritCaught
	setflag FLAG_TEMP_1
	end

PetalburgWoodsSE_EventScript_MespritCaught:: @ PondRock
	setflag FLAG_UNUSED_0x264
	end

PetalburgWoodsSE_EventScript_MespritAlreadyCaught:: @ PondRock
	msgbox PetalburgWoodsSE_Text_MespritAlreadyCaught, MSGBOX_SIGN
	end

PetalburgWoodsSE_Text_PondRock: @ PondRock
	.string "An ordinary rock that exudes\n"
	.string "a supernatural aura.$"

PetalburgWoodsSE_Text_Mesprit: @ PondRock
	.string "The supernatural aura is resonating!\p"
	.string "Emotions are running wild!$"

PetalburgWoodsSE_Text_MespritAlreadyCaught: @ PondRock
	.string "Emotions seem to linger on it.$"

PetalburgWoodsSE_EventScript_MossyRock:: @ MossyRock
	msgbox PetalburgWoodsSE_Text_MossyRock, MSGBOX_SIGN
	end

PetalburgWoodsSE_Text_MossyRock: @ MossyRock
	.string "A rock covered in moss.\p"
	.string "It has a mystical ambience.$"
