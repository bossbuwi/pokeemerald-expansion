RabbitHole_B1F_2R_MapScripts::
	.byte 0

RabbitHole_B1F_2R_EventScript_EdgeRock::
	msgbox RabbitHole_B1F_2R_Text_EdgeRock, MSGBOX_SIGN
	goto_if_set FLAG_UNUSED_0x275, RabbitHole_B1F_2R_EventScript_RegigigasAlreadyCaught
	goto_if_set FLAG_UNUSED_0x946, RabbitHole_B1F_2R_EventScript_RegigigasAlreadyInteracted
	goto RabbitHole_B1F_2R_EventScript_Regigigas
	end

RabbitHole_B1F_2R_EventScript_RegigigasAlreadyCaught::
	msgbox RabbitHole_B1F_2R_Text_RegigigasAlreadyCaught, MSGBOX_SIGN
	end

RabbitHole_B1F_2R_EventScript_RegigigasAlreadyInteracted::
	msgbox RabbitHole_B1F_2R_Text_RegigigasAlreadyCaught, MSGBOX_SIGN
	end

RabbitHole_B1F_2R_EventScript_RegigigasCaught::
	setflag FLAG_UNUSED_0x275
	end

RabbitHole_B1F_2R_EventScript_Regigigas::
	msgbox RabbitHole_B1F_2R_Text_Regigigas, MSGBOX_SIGN
	setwildbattle SPECIES_REGIGIGAS, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq RabbitHole_B1F_2R_EventScript_RegigigasCaught
	setflag FLAG_UNUSED_0x946
	end

RabbitHole_B1F_2R_Text_EdgeRock:
	.string "The rock glows a little bit.$"

RabbitHole_B1F_2R_Text_Regigigas:
	.string "Something is rising from the water!$"

RabbitHole_B1F_2R_Text_RegigigasAlreadyCaught:
	.string "The glow pulsates a bit.$"
