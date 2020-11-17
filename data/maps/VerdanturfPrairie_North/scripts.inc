VerdanturfPrairie_North_MapScripts::
	.byte 0

VerdanturfPrairie_North_EventScript_DroppedBag::
	msgbox VerdanturfPrairie_North_Text_DroppedBag, MSGBOX_SIGN
	goto_if_set FLAG_UNUSED_0x278, VerdanturfPrairie_North_EventScript_VirizionAlreadyCaught
	goto_if_set FLAG_UNUSED_0x949, VerdanturfPrairie_North_EventScript_VirizionAlreadyInteracted
	goto VerdanturfPrairie_North_EventScript_Virizion
	end

VerdanturfPrairie_North_EventScript_VirizionAlreadyCaught::
	msgbox VerdanturfPrairie_North_Text_VirizionAlreadyCaught, MSGBOX_SIGN
	end

VerdanturfPrairie_North_EventScript_VirizionAlreadyInteracted::
	msgbox VerdanturfPrairie_North_Text_VirizionAlreadyCaught, MSGBOX_SIGN
	end

VerdanturfPrairie_North_EventScript_VirizionCaught::
	setflag FLAG_UNUSED_0x278
	end

VerdanturfPrairie_North_EventScript_Virizion::
	msgbox VerdanturfPrairie_North_Text_Virizion, MSGBOX_SIGN
	setwildbattle SPECIES_VIRIZION, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq VerdanturfPrairie_North_EventScript_VirizionCaught
	setflag FLAG_UNUSED_0x949
	end

VerdanturfPrairie_North_Text_DroppedBag:
	.string "A tattered bag.$"

VerdanturfPrairie_North_Text_Virizion:
	.string "Someone's coming!$"

VerdanturfPrairie_North_Text_VirizionAlreadyCaught:
	.string "It exudes an aura of\n"
	.string "sumptuous elegance.$"
