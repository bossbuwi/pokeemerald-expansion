VerdanturfPrairie_East_MapScripts::
	.byte 0

VerdanturfPrairie_East_EventScript_TriangularStone::
	msgbox VerdanturfPrairie_East_Text_TriangularStone, MSGBOX_SIGN
	goto_if_set FLAG_UNUSED_0x277, VerdanturfPrairie_East_EventScript_TerrakionAlreadyCaught
	goto_if_set FLAG_UNUSED_0x948, VerdanturfPrairie_East_EventScript_TerrakionAlreadyInteracted
	goto VerdanturfPrairie_East_EventScript_Terrakion
	end

VerdanturfPrairie_East_EventScript_TerrakionAlreadyCaught::
	msgbox VerdanturfPrairie_East_Text_TerrakionAlreadyCaught, MSGBOX_SIGN
	end

VerdanturfPrairie_East_EventScript_TerrakionAlreadyInteracted::
	msgbox VerdanturfPrairie_East_Text_TerrakionAlreadyCaught, MSGBOX_SIGN
	end

VerdanturfPrairie_East_EventScript_TerrakionCaught::
	setflag FLAG_UNUSED_0x277
	end

VerdanturfPrairie_East_EventScript_Terrakion::
	msgbox VerdanturfPrairie_East_Text_Terrakion, MSGBOX_SIGN
	setwildbattle SPECIES_TERRAKION, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq VerdanturfPrairie_East_EventScript_TerrakionCaught
	setflag FLAG_UNUSED_0x948
	end

VerdanturfPrairie_East_Text_TriangularStone:
	.string "A peculiar stone.$"

VerdanturfPrairie_East_Text_Terrakion:
	.string "Someone's coming!$"

VerdanturfPrairie_East_Text_TerrakionAlreadyCaught:
	.string "It exudes an aura of terrifying strength.$"
