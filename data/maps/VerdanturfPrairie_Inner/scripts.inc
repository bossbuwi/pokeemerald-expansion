VerdanturfPrairie_Inner_MapScripts::
	.byte 0

VerdanturfPrairie_Inner_EventScript_CrossroadSign::
	msgbox VerdanturfPrairie_Inner_Text_CrossroadSign, MSGBOX_SIGN
	goto_if_set FLAG_UNUSED_0x276, VerdanturfPrairie_Inner_EventScript_CobalionAlreadyCaught
	goto_if_set FLAG_UNUSED_0x947, VerdanturfPrairie_Inner_EventScript_CobalionAlreadyInteracted
	goto VerdanturfPrairie_Inner_EventScript_Cobalion
	end

VerdanturfPrairie_Inner_EventScript_CobalionAlreadyCaught::
	msgbox VerdanturfPrairie_Inner_Text_CobalionAlreadyCaught, MSGBOX_SIGN
	end

VerdanturfPrairie_Inner_EventScript_CobalionAlreadyInteracted::
	msgbox VerdanturfPrairie_Inner_Text_CobalionAlreadyCaught, MSGBOX_SIGN
	end

VerdanturfPrairie_Inner_EventScript_CobalionCaught::
	setflag FLAG_UNUSED_0x276
	end

VerdanturfPrairie_Inner_EventScript_Cobalion::
	msgbox VerdanturfPrairie_Inner_Text_Cobalion, MSGBOX_SIGN
	setwildbattle SPECIES_COBALION, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq VerdanturfPrairie_Inner_EventScript_CobalionCaught
	setflag FLAG_UNUSED_0x947
	end

VerdanturfPrairie_Inner_Text_CrossroadSign:
	.string "You are at the crossroads of elegance\n"
	.string "and strength. Unite both to obtain\l"
	.string "unyielding resolve.$"

VerdanturfPrairie_Inner_Text_Cobalion:
	.string "Someone's coming!$"

VerdanturfPrairie_Inner_Text_CobalionAlreadyCaught:
	.string "Never let your inspirations waver.$"
