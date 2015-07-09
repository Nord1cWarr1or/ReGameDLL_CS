/*
*
*   This program is free software; you can redistribute it and/or modify it
*   under the terms of the GNU General Public License as published by the
*   Free Software Foundation; either version 2 of the License, or (at
*   your option) any later version.
*
*   This program is distributed in the hope that it will be useful, but
*   WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*   General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software Foundation,
*   Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*   In addition, as a special exception, the author gives permission to
*   link the code of this program with the Half-Life Game Engine ("HL
*   Engine") and Modified Game Libraries ("MODs") developed by Valve,
*   L.L.C ("Valve").  You must obey the GNU General Public License in all
*   respects for all of the code used other than the HL Engine and MODs
*   from Valve.  If you modify this file, you may extend this exception
*   to your version of the file, but you are not obligated to do so.  If
*   you do not wish to do so, delete this exception statement from your
*   version.
*
*/

#ifndef PLAYER_H
#define PLAYER_H
#ifdef _WIN32
#pragma once
#endif

#include "hintmessage.h"
//#include "weapons.h"

#define MAX_BUFFER_MENU			175//?
#define MAX_BUFFER_MENU_BRIEFING	50

#define MAX_PLAYER_NAME_LENGTH		32
#define MAX_AUTOBUY_LENGTH		256
#define MAX_REBUY_LENGTH		256

#define MAX_RECENT_PATH			20

#define PLAYER_FATAL_FALL_SPEED		1100.0f
#define PLAYER_MAX_SAFE_FALL_SPEED	500.0f
#define	PLAYER_SEARCH_RADIUS		64.0f

// damage per unit per second.
#define DAMAGE_FOR_FALL_SPEED		100.0f / (PLAYER_FATAL_FALL_SPEED - PLAYER_MAX_SAFE_FALL_SPEED)
#define PLAYER_MIN_BOUNCE_SPEED		350.0f

// won't punch player's screen/make scrape noise unless player falling at least this fast.
#define PLAYER_FALL_PUNCH_THRESHHOLD	250.0f

// Money blinks few of times on the freeze period
// NOTE: It works for CZ
#define MONEY_BLINK_AMOUNT		30

#define PFLAG_ONLADDER			(1<<0)
#define PFLAG_ONSWING			(1<<0)
#define PFLAG_ONTRAIN			(1<<1)
#define PFLAG_ONBARNACLE		(1<<2)
#define PFLAG_DUCKING			(1<<3)
#define PFLAG_USING			(1<<4)
#define PFLAG_OBSERVER			(1<<5)

#define TRAIN_OFF			0x00
#define TRAIN_NEUTRAL			0x01
#define TRAIN_SLOW			0x02
#define TRAIN_MEDIUM			0x03
#define TRAIN_FAST			0x04
#define TRAIN_BACK			0x05

#define TRAIN_ACTIVE			0x80
#define TRAIN_NEW			0xc0

#define DHF_ROUND_STARTED		(1<<1)
#define DHF_HOSTAGE_SEEN_FAR		(1<<2)
#define DHF_HOSTAGE_SEEN_NEAR		(1<<3)
#define DHF_HOSTAGE_USED		(1<<4)
#define DHF_HOSTAGE_INJURED		(1<<5)
#define DHF_HOSTAGE_KILLED		(1<<6)
#define DHF_FRIEND_SEEN			(1<<7)
#define DHF_ENEMY_SEEN			(1<<8)
#define DHF_FRIEND_INJURED		(1<<9)
#define DHF_FRIEND_KILLED		(1<<10)
#define DHF_ENEMY_KILLED		(1<<11)
#define DHF_BOMB_RETRIEVED		(1<<12)
#define DHF_AMMO_EXHAUSTED		(1<<15)
#define DHF_IN_TARGET_ZONE		(1<<16)
#define DHF_IN_RESCUE_ZONE		(1<<17)
#define DHF_IN_ESCAPE_ZONE		(1<<18)
#define DHF_IN_VIPSAFETY_ZONE		(1<<19)
#define DHF_NIGHTVISION			(1<<20)
#define DHF_HOSTAGE_CTMOVE		(1<<21)
#define	DHF_SPEC_DUCK			(1<<22)

#define DHM_ROUND_CLEAR			(DHF_ROUND_STARTED | DHF_HOSTAGE_KILLED | DHF_FRIEND_KILLED | DHF_BOMB_RETRIEVED)
#define DHM_CONNECT_CLEAR		(DHF_HOSTAGE_SEEN_FAR | DHF_HOSTAGE_SEEN_NEAR | DHF_HOSTAGE_USED | DHF_HOSTAGE_INJURED | DHF_FRIEND_SEEN | DHF_ENEMY_SEEN | DHF_FRIEND_INJURED | DHF_ENEMY_KILLED | DHF_AMMO_EXHAUSTED | DHF_IN_TARGET_ZONE | DHF_IN_RESCUE_ZONE | DHF_IN_ESCAPE_ZONE | DHF_IN_VIPSAFETY_ZONE | DHF_HOSTAGE_CTMOVE | DHF_SPEC_DUCK)

#define SIGNAL_BUY			(1<<0)
#define SIGNAL_BOMB			(1<<1)
#define SIGNAL_RESCUE			(1<<2)
#define SIGNAL_ESCAPE			(1<<3)
#define SIGNAL_VIPSAFETY		(1<<4)

#define IGNOREMSG_NONE			0
#define IGNOREMSG_ENEMY			1
#define IGNOREMSG_TEAM			2

// max of 4 suit sentences queued up at any time
#define CSUITPLAYLIST			4

#define SUIT_GROUP			TRUE
#define SUIT_SENTENCE			FALSE

#define SUIT_REPEAT_OK			0
#define SUIT_NEXT_IN_30SEC		30
#define SUIT_NEXT_IN_1MIN		60
#define SUIT_NEXT_IN_5MIN		300
#define SUIT_NEXT_IN_10MIN		600
#define SUIT_NEXT_IN_30MIN		1800
#define SUIT_NEXT_IN_1HOUR		3600

#define TEAM_NAME_LENGTH		16

#define MAX_ID_RANGE			2048
#define MAX_SPECTATOR_ID_RANGE		8192
#define SBAR_STRING_SIZE		128

#define SBAR_TARGETTYPE_TEAMMATE	1
#define SBAR_TARGETTYPE_ENEMY		2
#define SBAR_TARGETTYPE_HOSTAGE		3

#define CHAT_INTERVAL			1.0f
#define CSUITNOREPEAT			32

//#define SOUND_FLASHLIGHT_ON	"items/flashlight1.wav"
//#define SOUND_FLASHLIGHT_OFF	"items/flashlight1.wav"

typedef enum
{
	PLAYER_IDLE,
	PLAYER_WALK,
	PLAYER_JUMP,
	PLAYER_SUPERJUMP,
	PLAYER_DIE,
	PLAYER_ATTACK1,
	PLAYER_ATTACK2,
	PLAYER_FLINCH,
	PLAYER_LARGE_FLINCH,
	PLAYER_RELOAD,
	PLAYER_HOLDBOMB
} PLAYER_ANIM;

typedef enum
{
	Menu_OFF,
	Menu_ChooseTeam,
	Menu_IGChooseTeam,
	Menu_ChooseAppearance,
	Menu_Buy,
	Menu_BuyPistol,
	Menu_BuyRifle,
	Menu_BuyMachineGun,
	Menu_BuyShotgun,
	Menu_BuySubMachineGun,
	Menu_BuyItem,
	Menu_Radio1,
	Menu_Radio2,
	Menu_Radio3,
	Menu_ClientBuy
} _Menu;

typedef enum
{
	UNASSIGNED,
	TERRORIST,
	CT,
	SPECTATOR,
} TeamName;

typedef enum
{
	MODEL_UNASSIGNED,
	MODEL_URBAN,
	MODEL_TERROR,
	MODEL_LEET,
	MODEL_ARCTIC,
	MODEL_GSG9,
	MODEL_GIGN,
	MODEL_SAS,
	MODEL_GUERILLA,
	MODEL_VIP,
	MODEL_MILITIA,
	MODEL_SPETSNAZ
} ModelName;

typedef enum
{
	JOINED,
	SHOWLTEXT,
	READINGLTEXT,
	SHOWTEAMSELECT,
	PICKINGTEAM,
	GETINTOGAME
} JoinState;

typedef enum
{
	CMD_SAY = 0,
	CMD_SAYTEAM,
	CMD_FULLUPDATE,
	CMD_VOTE,
	CMD_VOTEMAP,
	CMD_LISTMAPS,
	CMD_LISTPLAYERS,
	CMD_NIGHTVISION,
	COMMANDS_TO_TRACK,
} TrackCommands;

typedef struct
{
	int m_primaryWeapon;
	int m_primaryAmmo;
	int m_secondaryWeapon;
	int m_secondaryAmmo;
	int m_heGrenade;
	int m_flashbang;
	int m_smokeGrenade;
	int m_defuser;
	int m_nightVision;
	int m_armor;
} RebuyStruct;

typedef enum
{
	THROW_NONE,
	THROW_FORWARD,
	THROW_BACKWARD,
	THROW_HITVEL,
	THROW_BOMB,
	THROW_GRENADE,
	THROW_HITVEL_MINUS_AIRVEL
} ThrowDirection;

enum sbar_data
{
	SBAR_ID_TARGETTYPE = 1,
	SBAR_ID_TARGETNAME,
	SBAR_ID_TARGETHEALTH,
	SBAR_END
};

typedef enum
{
	SILENT,
	CALM,
	INTENSE
} MusicState;

struct WeaponStruct
{
	int m_type;
	int m_price;
	int m_side;
	int m_slot;
	int m_ammoPrice;

};/* size: 20, cachelines: 1, members: 5 */

#ifdef HOOK_GAMEDLL

#define m_szPoses (*pm_szPoses)
#define g_weaponStruct (*pg_weaponStruct)
#define gEvilImpulse101 (*pgEvilImpulse101)
#define g_szMapBriefingText (*pg_szMapBriefingText)
#define gInitHUD (*pgInitHUD)
#define sv_aim (*psv_aim)
#define giPrecacheGrunt (*pgiPrecacheGrunt)
#define gmsgWeapPickup (*pgmsgWeapPickup)
#define gmsgHudText (*pgmsgHudText)
#define gmsgHudTextArgs (*pgmsgHudTextArgs)
#define gmsgShake (*pgmsgShake)
#define gmsgFade (*pgmsgFade)
#define gmsgFlashlight (*pgmsgFlashlight)
//#define gmsgFlashBattery (*pgmsgFlashBattery)
//#define gmsgResetHUD (*pgmsgResetHUD)
//#define gmsgInitHUD (*pgmsgInitHUD)
//#define gmsgViewMode (*pgmsgViewMode)
//#define gmsgShowGameTitle (*pgmsgShowGameTitle)
#define gmsgCurWeapon (*pgmsgCurWeapon)
//#define gmsgHealth (*pgmsgHealth)
//#define gmsgDamage (*pgmsgDamage)
//#define gmsgBattery (*pgmsgBattery)
//#define gmsgTrain (*pgmsgTrain)
#define gmsgLogo (*pgmsgLogo)
#define gmsgWeaponList (*pgmsgWeaponList)
#define gmsgAmmoX (*pgmsgAmmoX)
//#define gmsgDeathMsg (*pgmsgDeathMsg)
#define gmsgScoreAttrib (*pgmsgScoreAttrib)
#define gmsgScoreInfo (*pgmsgScoreInfo)
#define gmsgTeamInfo (*pgmsgTeamInfo)
//#define gmsgTeamScore (*pgmsgTeamScore)
//#define gmsgGameMode (*pgmsgGameMode)
//#define gmsgMOTD (*pgmsgMOTD)
//#define gmsgServerName (*pgmsgServerName)
#define gmsgAmmoPickup (*pgmsgAmmoPickup)
#define gmsgItemPickup (*pgmsgItemPickup)
//#define gmsgHideWeapon (*pgmsgHideWeapon)
#define gmsgSayText (*pgmsgSayText)
#define gmsgTextMsg (*pgmsgTextMsg)
#define gmsgSetFOV (*pgmsgSetFOV)
#define gmsgShowMenu (*pgmsgShowMenu)
#define gmsgSendAudio (*pgmsgSendAudio)
#define gmsgRoundTime (*pgmsgRoundTime)
#define gmsgMoney (*pgmsgMoney)
#define gmsgBlinkAcct (*pgmsgBlinkAcct)
#define gmsgArmorType (*pgmsgArmorType)
#define gmsgStatusValue (*pgmsgStatusValue)
#define gmsgStatusText (*pgmsgStatusText)
#define gmsgStatusIcon (*pgmsgStatusIcon)
#define gmsgBarTime (*pgmsgBarTime)
#define gmsgReloadSound (*pgmsgReloadSound)
#define gmsgCrosshair (*pgmsgCrosshair)
#define gmsgNVGToggle (*pgmsgNVGToggle)
//#define gmsgRadar (*pgmsgRadar)
#define gmsgSpectator (*pgmsgSpectator)
//#define gmsgVGUIMenu (*pgmsgVGUIMenu)
#define gmsgCZCareer (*pgmsgCZCareer)
//#define gmsgCZCareerHUD (*pgmsgCZCareerHUD)
#define gmsgTaskTime (*pgmsgTaskTime)
//#define gmsgTutorText (*pgmsgTutorText)
#define gmsgTutorLine (*pgmsgTutorLine)
//#define gmsgShadowIdx (*pgmsgShadowIdx)
#define gmsgTutorState (*pgmsgTutorState)
#define gmsgTutorClose (*pgmsgTutorClose)
//#define gmsgAllowSpec (*pgmsgAllowSpec)
#define gmsgBombDrop (*pgmsgBombDrop)
//#define gmsgBombPickup (*pgmsgBombPickup)
#define gmsgHostagePos (*pgmsgHostagePos)
//#define gmsgHostageK (*pgmsgHostageK)
#define gmsgGeigerRange (*pgmsgGeigerRange)
#define gmsgSendCorpse (*pgmsgSendCorpse)
//#define gmsgHLTV (*pgmsgHLTV)
//#define gmsgSpecHealth (*pgmsgSpecHealth)
//#define gmsgForceCam (*pgmsgForceCam)
//#define gmsgADStop (*pgmsgADStop)
#define gmsgReceiveW (*pgmsgReceiveW)
#define gmsgScenarioIcon (*pgmsgScenarioIcon)
#define gmsgBotVoice (*pgmsgBotVoice)
#define gmsgBuyClose (*pgmsgBuyClose)
#define gmsgItemStatus (*pgmsgItemStatus)
#define gmsgLocation (*pgmsgLocation)
#define gmsgSpecHealth2 (*pgmsgSpecHealth2)
#define gmsgBarTime2 (*pgmsgBarTime2)
#define gmsgBotProgress (*pgmsgBotProgress)
//#define gmsgBrass (*pgmsgBrass)
//#define gmsgFog (*pgmsgFog)
//#define gmsgShowTimer (*pgmsgShowTimer)

#endif // HOOK_GAMEDLL

/* <14efbf> ../cstrike/dlls/player.cpp:9418 */
class CStripWeapons: public CPointEntity
{
public:
	virtual void Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);

#ifdef HOOK_GAMEDLL

	void Use_(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);

#endif // HOOK_GAMEDLL

};/* size: 152, cachelines: 3, members: 1 */

/* <14f06c> ../cstrike/dlls/player.cpp:9543 */
class CInfoIntermission: public CPointEntity
{
public:
	virtual void Spawn(void);
	virtual void Think(void);

#ifdef HOOK_GAMEDLL

	void Spawn_(void);
	void Think_(void);

#endif // HOOK_GAMEDLL

};/* size: 152, cachelines: 3, members: 1 */

/* <14ef4d> ../cstrike/dlls/player.cpp:9361 */
class CDeadHEV: public CBaseMonster
{
public:
	virtual void Spawn(void);
	virtual void KeyValue(KeyValueData *pkvd);
	virtual int Classify(void);

#ifdef HOOK_GAMEDLL

	void Spawn_(void);
	void KeyValue_(KeyValueData *pkvd);
	int Classify_(void);

#endif // HOOK_GAMEDLL

public:

	int m_iPose;
	static char *m_szPoses[4];

};/* size: 408, cachelines: 7, members: 3 */

/* <14ee80> ../cstrike/dlls/player.cpp:7001 */
class CSprayCan: public CBaseEntity
{
public:
	virtual void Think(void);
	virtual int ObjectCaps(void)
	{
		return ObjectCaps_();
	}

#ifdef HOOK_GAMEDLL

	void Think_(void);
	int ObjectCaps_(void)
	{
		return FCAP_DONT_SAVE;
	}

#endif // HOOK_GAMEDLL

public:
	NOBODY void Spawn(entvars_t *pevOwner);

};/* size: 152, cachelines: 3, members: 1 */

/* <14eea3> ../cstrike/dlls/player.cpp:7057 */
class CBloodSplat: public CBaseEntity
{
public:
	void Spawn(entvars_t *pevOwner);
	void Spray(void);

};/* size: 152, cachelines: 3, members: 1 */

/* <48ed5e> ../cstrike/dlls/player.h:250 */
class CBasePlayer: public CBaseMonster
{
public:
	enum { MaxLocationLen = 32 };

	NOBODY virtual void Spawn(void);
	NOBODY virtual void Precache(void);
	NOBODY virtual int Save(CSave &save);
	NOBODY virtual int Restore(CRestore &restore);
	NOBODY virtual int ObjectCaps(void)
	{
		return ObjectCaps_();
	}
	virtual int Classify(void);
	virtual void TraceAttack(entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType);
	NOBODY virtual int TakeDamage(entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);
	NOBODY virtual int TakeHealth(float flHealth, int bitsDamageType);
	NOBODY virtual void Killed(entvars_t *pevAttacker, int iGib);
	virtual void AddPoints(int score, BOOL bAllowNegativeScore);
	NOBODY virtual void AddPointsToTeam(int score, BOOL bAllowNegativeScore);
	virtual BOOL AddPlayerItem(CBasePlayerItem *pItem);
	virtual BOOL RemovePlayerItem(CBasePlayerItem *pItem);
	virtual int GiveAmmo(int iAmount, char *szName, int iMax);
	NOBODY virtual void StartSneaking(void)
	{
		StartSneaking_();
	}
	NOBODY virtual void StopSneaking(void)
	{
		StopSneaking_();
	}
	NOBODY virtual BOOL IsSneaking(void)
	{
		return IsSneaking_();
	}
	NOBODY virtual BOOL IsAlive(void)
	{
		return IsAlive_();
	}
	NOBODY virtual BOOL IsPlayer(void)
	{
		return IsPlayer_();
	}
	NOBODY virtual BOOL IsNetClient(void)
	{
		return IsNetClient_();
	}
	virtual const char *TeamID(void);
	virtual BOOL FBecomeProne(void);
	NOBODY virtual Vector BodyTarget(const Vector &posSrc)
	{
		return BodyTarget_(posSrc);
	}
	virtual int Illumination(void);
	NOBODY virtual BOOL ShouldFadeOnDeath(void)
	{
		return ShouldFadeOnDeath_();
	}
	NOBODY virtual void ResetMaxSpeed(void);
	NOBODY virtual void Jump(void);
	NOBODY virtual void Duck(void);
	NOBODY virtual void PreThink(void);
	NOBODY virtual void PostThink(void);
	NOBODY virtual Vector GetGunPosition(void);
	NOBODY virtual BOOL IsBot(void)
	{
		return IsBot_();
	}
	NOBODY virtual void UpdateClientData(void);
	NOBODY virtual void ImpulseCommands(void);
	virtual void RoundRespawn(void);
	virtual Vector GetAutoaimVector(float flDelta);
	virtual void Blind(float flUntilTime, float flHoldTime, float flFadeTime, int iAlpha);
	NOBODY virtual void OnTouchingWeapon(CWeaponBox *pWeapon)
	{
		OnTouchingWeapon_(pWeapon);
	}

#ifdef HOOK_GAMEDLL

	void Spawn_(void);
	void Precache_(void);
	int Save_(CSave &save);
	int Restore_(CRestore &restore);
	int ObjectCaps_(void)
	{
		return (CBaseMonster::ObjectCaps() & ~FCAP_ACROSS_TRANSITION);
	}
	int Classify_(void);
	void TraceAttack_(entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType);
	int TakeDamage_(entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);
	int TakeHealth_(float flHealth, int bitsDamageType);
	void Killed_(entvars_t *pevAttacker, int iGib);
	void AddPoints_(int score, BOOL bAllowNegativeScore);
	void AddPointsToTeam_(int score, BOOL bAllowNegativeScore);
	BOOL AddPlayerItem_(CBasePlayerItem *pItem);
	BOOL RemovePlayerItem_(CBasePlayerItem *pItem);
	int GiveAmmo_(int iAmount,char *szName,int iMax);
	void StartSneaking_(void)
	{
		m_tSneaking = gpGlobals->time - 1;
	}
	void StopSneaking_(void)
	{
		m_tSneaking = gpGlobals->time + 30;
	}
	BOOL IsSneaking_(void)
	{
		return m_tSneaking <= gpGlobals->time;
	}
	BOOL IsAlive_(void)
	{
		return (pev->deadflag == DEAD_NO && pev->health > 0.0f);
	}
	BOOL IsPlayer_(void)
	{
		return (pev->flags & FL_SPECTATOR) != FL_SPECTATOR;
	}
	BOOL IsNetClient_(void)
	{
		return TRUE;
	}
	const char *TeamID_(void);
	BOOL FBecomeProne_(void);
	Vector BodyTarget_(const Vector &posSrc)
	{
		return Center() + pev->view_ofs * RANDOM_FLOAT(0.5, 1.1);
	}
	int Illumination_(void);
	BOOL ShouldFadeOnDeath_(void)
	{
		return FALSE;
	}
	void ResetMaxSpeed_(void);
	void Jump_(void);
	void Duck_(void);
	void PreThink_(void);
	void PostThink_(void);
	Vector GetGunPosition_(void);
	BOOL IsBot_(void)
	{
		return FALSE;
	}
	void UpdateClientData_(void);
	void ImpulseCommands_(void);
	void RoundRespawn_(void);
	Vector GetAutoaimVector_(float flDelta);
	void Blind_(float flUntilTime, float flHoldTime, float flFadeTime, int iAlpha);
	void OnTouchingWeapon_(CWeaponBox *pWeapon)
	{
		;
	}

#endif // HOOK_GAMEDLL

public:
	void SpawnClientSideCorpse(void);
	void Observer_FindNextPlayer(bool bReverse, const char *name = NULL);
	CBaseEntity *Observer_IsValidTarget(int iPlayerIndex, bool bSameTeam);
	void Observer_HandleButtons(void);
	void Observer_SetMode(int iMode);
	void Observer_CheckTarget(void);
	void Observer_CheckProperties(void);
	int IsObserver(void)
	{
		return pev->iuser1;
	}
	NOBODY void PlantC4(void);
	void Radio(const char *msg_id, const char *msg_verbose, short pitch = 100, bool showIcon = true);
	NOXREF CBasePlayer *GetNextRadioRecipient(CBasePlayer *pStartPlayer);
	void SmartRadio(void);
	NOXREF void ThrowWeapon(char *pszItemName);
	NOXREF void ThrowPrimary(void);
	void AddAccount(int amount, bool bTrackChange = true);
	NOBODY void Disappear(void);
	void MakeVIP(void);
	NOBODY bool CanPlayerBuy(bool display);
	void SwitchTeam(void);
	void TabulateAmmo(void);
	void Pain(int m_LastHitGroup, bool HasArmour);
	BOOL IsBombGuy(void);
	bool IsLookingAtPosition(Vector *pos, float angleTolerance = 20.0f);
	NOBODY void Reset();
	void SetScoreboardAttributes(CBasePlayer *destination = NULL);
	NOBODY void RenewItems(void);
	void PackDeadPlayerItems(void);
	void GiveDefaultItems(void);
	void RemoveAllItems(BOOL removeSuit);
	void SetBombIcon(BOOL bFlash);
	void SetProgressBarTime(int time);
	void SetProgressBarTime2(int time, float timeElapsed);
	void SetPlayerModel(BOOL HasC4);
	void SetNewPlayerModel(const char *modelName);
	BOOL SwitchWeapon(CBasePlayerItem *pWeapon);
	NOXREF void CheckPowerups(entvars_t *pev);
	bool CanAffordPrimary(void);
	bool CanAffordPrimaryAmmo(void);
	bool CanAffordSecondaryAmmo(void);
	bool CanAffordArmor(void);
	bool CanAffordDefuseKit(void);
	bool CanAffordGrenade(void);
	bool NeedsPrimaryAmmo(void);
	bool NeedsSecondaryAmmo(void);
	bool NeedsArmor(void);
	bool NeedsDefuseKit(void);
	bool NeedsGrenade(void);
	BOOL IsOnLadder(void);
	BOOL FlashlightIsOn(void);
	void FlashlightTurnOn(void);
	void FlashlightTurnOff(void);
	NOBODY void UpdatePlayerSound(void);
	NOXREF void DeathSound(void);
	void SetAnimation(PLAYER_ANIM playerAnim);
	NOBODY void SetWeaponAnimType(const char *szExtention);
	void CheatImpulseCommands(int iImpulse);
	NOXREF void StartDeathCam(void);
	NOBODY void StartObserver(Vector vecPosition, Vector vecViewAngle);
	NOBODY void HandleSignals(void);
	void DropPlayerItem(const char *pszItemName);
	BOOL HasPlayerItem(CBasePlayerItem *pCheckItem);
	BOOL HasNamedPlayerItem(const char *pszItemName);
	NOXREF BOOL HasWeapons(void);
	NOXREF void SelectPrevItem(int iItem);
	NOBODY void SelectNextItem(int iItem);
	void SelectLastItem(void);
	NOBODY void SelectItem(const char *pstr);
	NOXREF void ItemPreFrame(void);
	NOXREF void ItemPostFrame(void);
	void GiveNamedItem(const char *pszName);
	void EnableControl(BOOL fControl);
	NOBODY bool HintMessage(const char *pMessage, BOOL bDisplayIfPlayerDead = FALSE, BOOL bOverride = FALSE);
	void SendAmmoUpdate(void);
	NOXREF void SendFOV(int fov);
	NOBODY void WaterMove(void);
	NOBODY void EXPORT PlayerDeathThink(void);
	void PlayerUse(void);
	NOBODY void HostageUsed(void);
	NOBODY void JoiningThink(void);
	NOBODY void RemoveLevelText(void);
	void WINAPI_HOOK MenuPrint(const char *msg);
	void ResetMenu(void);
	void SyncRoundTimer(void);
	NOBODY void CheckSuitUpdate(void);
	void SetSuitUpdate(char *name = NULL, int fgroup = 0, int iNoRepeatTime = 0);
	NOXREF void UpdateGeigerCounter(void);
	NOBODY void CheckTimeBasedDamage(void);
	NOXREF void BarnacleVictimBitten(entvars_t *pevBarnacle);
	NOXREF void BarnacleVictimReleased(void);
	static int GetAmmoIndex(const char *psz);
	int AmmoInventory(int iAmmoIndex);
	NOBODY void ResetAutoaim(void);
	Vector AutoaimDeflection(class Vector &vecSrc, float flDist, float flDelta);
	NOBODY void ForceClientDllUpdate(void);
	void DeathMessage(entvars_t *pevAttacker) { };
	void SetCustomDecalFrames(int);
	NOXREF int GetCustomDecalFrames(void);
	NOXREF void InitStatusBar(void);
	void UpdateStatusBar(void);
	void StudioEstimateGait(void);
	NOXREF void StudioPlayerBlend(int *pBlend, float *pPitch);
	NOXREF void CalculatePitchBlend(void);
	void CalculateYawBlend(void);
	void StudioProcessGait(void);
	NOXREF void SendHostagePos(void);
	void SendHostageIcons(void);
	NOXREF void ResetStamina(void);
	NOXREF BOOL IsArmored(int nHitGroup);
	NOXREF BOOL ShouldDoLargeFlinch(int nHitGroup, int nGunType);
	void SetPrefsFromUserinfo(char *infobuffer);
	void SendWeatherInfo(void);
	void UpdateShieldCrosshair(bool);
	bool HasShield(void);
	bool IsProtectedByShield(void)
	{
		return HasShield() && m_bShieldDrawn;
	}
	void RemoveShield(void);
	void DropShield(bool);
	NOBODY void GiveShield(bool);
	bool IsHittingShield(Vector &vecDirection, TraceResult *ptr);
	bool IsReloading(void)
	{
		if (m_pActiveItem && ((CBasePlayerWeapon *)m_pActiveItem)->m_fInReload)
			return true;

		return false;
	}
	NOBODY bool IsBlind(void);
	NOBODY bool IsAutoFollowAllowed(void);
	NOBODY void InhibitAutoFollow(float);
	NOBODY void AllowAutoFollow(void);
	void ClearAutoBuyData(void);
	void AddAutoBuyData(const char *str);
	NOBODY void AutoBuy(void);
	NOBODY void ClientCommand(const char *cmd, const char *arg1 = NULL, const char *arg2 = NULL, const char *arg3 = NULL);
	void PrioritizeAutoBuyString(char *autobuyString, const char *priorityString);
	NOBODY const char *PickPrimaryCareerTaskWeapon(void);
	NOBODY const char *PickSecondaryCareerTaskWeapon(void);
	NOXREF const char *PickFlashKillWeaponString(void);
	NOXREF const char *PickGrenadeKillWeaponString(void);
	NOXREF bool ShouldExecuteAutoBuyCommand(AutoBuyInfoStruct *commandInfo, bool boughtPrimary, bool boughtSecondary);
	void PostAutoBuyCommandProcessing(AutoBuyInfoStruct *commandInfo, bool &boughtPrimary, bool &boughtSecondary);
	void ParseAutoBuyString(const char *string, bool &boughtPrimary, bool &boughtSecondary);
	NOXREF AutoBuyInfoStruct *GetAutoBuyCommandInfo(const char *command);
	NOBODY void InitRebuyData(const char *str);
	void BuildRebuyStruct(void);
	void Rebuy(void);
	NOXREF void RebuyPrimaryWeapon(void);
	NOXREF void RebuyPrimaryAmmo(void);
	NOXREF void RebuySecondaryWeapon(void);
	NOXREF void RebuySecondaryAmmo(void);
	NOXREF void RebuyHEGrenade(void);
	NOXREF void RebuyFlashbang(void);
	NOXREF void RebuySmokeGrenade(void);
	void RebuyDefuser(void);
	void RebuyNightVision(void);
	void RebuyArmor(void);
	void UpdateLocation(bool forceUpdate);
	void SetObserverAutoDirector(bool val)
	{
		m_bObserverAutoDirector = val;
	}
	bool IsObservingPlayer(CBasePlayer *pPlayer);
	bool CanSwitchObserverModes(void)
	{
		return m_canSwitchObserverModes;
	}
	NOBODY void Intense(void)
	{
		//m_musicState = INTENSE;
		//m_intenseTimestamp = gpGlobals->time;
	}

public:
	int random_seed;
	unsigned short m_usPlayerBleed;
	EHANDLE m_hObserverTarget;
	float m_flNextObserverInput;
	int m_iObserverWeapon;
	int m_iObserverC4State;
	bool m_bObserverHasDefuser;
	int m_iObserverLastMode;
	float m_flFlinchTime;
	float m_flAnimTime;
	bool m_bHighDamage;
	float m_flVelocityModifier;
	int m_iLastZoom;
	bool m_bResumeZoom;
	float m_flEjectBrass;
	int m_iKevlar;
	bool m_bNotKilled;
	TeamName m_iTeam;
	int m_iAccount;
	bool m_bHasPrimary;
	float m_flDeathThrowTime;
	int m_iThrowDirection;
	float m_flLastTalk;
	bool m_bJustConnected;
	bool m_bContextHelp;
	JoinState m_iJoiningState;
	CBaseEntity *m_pIntroCamera;
	float m_fIntroCamTime;
	float m_fLastMovement;
	bool m_bMissionBriefing;
	bool m_bTeamChanged;
	ModelName m_iModelName;
	int m_iTeamKills;
	int m_iIgnoreGlobalChat;
	bool m_bHasNightVision;
	bool m_bNightVisionOn;
	Vector m_vRecentPath[ MAX_RECENT_PATH ];
	float m_flIdleCheckTime;
	float m_flRadioTime;
	int m_iRadioMessages;
	bool m_bIgnoreRadio;
	bool m_bHasC4;
	bool m_bHasDefuser;
	bool m_bKilledByBomb;
	Vector m_vBlastVector;
	bool m_bKilledByGrenade;
	CHintMessageQueue m_hintMessageQueue;
	int m_flDisplayHistory;
	_Menu m_iMenu;
	int m_iChaseTarget;
	CBaseEntity *m_pChaseTarget;
	float m_fCamSwitch;
	bool m_bEscaped;
	bool m_bIsVIP;
	float m_tmNextRadarUpdate;
	Vector m_vLastOrigin;
	int m_iCurrentKickVote;
	float m_flNextVoteTime;
	bool m_bJustKilledTeammate;
	int m_iHostagesKilled;
	int m_iMapVote;
	bool m_bCanShoot;
	float m_flLastFired;
	float m_flLastAttackedTeammate;
	bool m_bHeadshotKilled;
	bool m_bPunishedForTK;
	bool m_bReceivesNoMoneyNextRound;
	int m_iTimeCheckAllowed;
	bool m_bHasChangedName;
	char m_szNewName[ MAX_PLAYER_NAME_LENGTH ];
	bool m_bIsDefusing;
	float m_tmHandleSignals;
	CUnifiedSignals m_signals;
	edict_t *m_pentCurBombTarget;
	int m_iPlayerSound;
	int m_iTargetVolume;
	int m_iWeaponVolume;
	int m_iExtraSoundTypes;
	int m_iWeaponFlash;
	float m_flStopExtraSoundTime;
	float m_flFlashLightTime;
	int m_iFlashBattery;
	int m_afButtonLast;
	int m_afButtonPressed;
	int m_afButtonReleased;
	edict_t *m_pentSndLast;
	float m_flSndRoomtype;
	float m_flSndRange;
	float m_flFallVelocity;
	int m_rgItems[ MAX_ITEMS ];
	int m_fNewAmmo;
	unsigned int m_afPhysicsFlags;
	float m_fNextSuicideTime;
	float m_flTimeStepSound;
	float m_flTimeWeaponIdle;
	float m_flSwimTime;
	float m_flDuckTime;
	float m_flWallJumpTime;
	float m_flSuitUpdate;
	int m_rgSuitPlayList[ CSUITPLAYLIST ];
	int m_iSuitPlayNext;
	int m_rgiSuitNoRepeat[ CSUITNOREPEAT ];
	float m_rgflSuitNoRepeatTime[ CSUITNOREPEAT ];
	int m_lastDamageAmount;
	float m_tbdPrev;
	float m_flgeigerRange;
	float m_flgeigerDelay;
	int m_igeigerRangePrev;
	int m_iStepLeft;
	char m_szTextureName[ CBTEXTURENAMEMAX ];
	char m_chTextureType;
	int m_idrowndmg;
	int m_idrownrestored;
	int m_bitsHUDDamage;
	BOOL m_fInitHUD;
	BOOL m_fGameHUDInitialized;
	int m_iTrain;
	BOOL m_fWeapon;
	EHANDLE m_pTank;
	float m_fDeadTime;
	BOOL m_fNoPlayerSound;
	BOOL m_fLongJump;
	float m_tSneaking;
	int m_iUpdateTime;
	int m_iClientHealth;
	int m_iClientBattery;
	int m_iHideHUD;
	int m_iClientHideHUD;
	int m_iFOV;
	int m_iClientFOV;
	int m_iNumSpawns;
	CBaseEntity *m_pObserver;
	CBasePlayerItem *m_rgpPlayerItems[ MAX_ITEM_TYPES ];
	CBasePlayerItem *m_pActiveItem;
	CBasePlayerItem *m_pClientActiveItem;
	CBasePlayerItem *m_pLastItem;
	int m_rgAmmo[ MAX_AMMO_SLOTS ];
	int m_rgAmmoLast[ MAX_AMMO_SLOTS ];
	Vector m_vecAutoAim;
	BOOL m_fOnTarget;
	int m_iDeaths;
	int m_izSBarState[SBAR_END];
	float m_flNextSBarUpdateTime;
	float m_flStatusBarDisappearDelay;
	char m_SbarString0[ SBAR_STRING_SIZE ];
	int m_lastx;
	int m_lasty;
	int m_nCustomSprayFrames;
	float m_flNextDecalTime;
	char m_szTeamName[ TEAM_NAME_LENGTH ];

	static TYPEDESCRIPTION IMPLEMENT_ARRAY(m_playerSaveData)[40];

//TOOD: check out!
//protected:

	int m_modelIndexPlayer;//++1964
	char m_szAnimExtention[32];
	int m_iGaitsequence;

	float m_flGaitframe;
	float m_flGaityaw;
	Vector m_prevgaitorigin;
	float m_flPitch;
	float m_flYaw;
	float m_flGaitMovement;
	int m_iAutoWepSwitch;
	bool m_bVGUIMenus;
	bool m_bShowHints;
	bool m_bShieldDrawn;
	bool m_bOwnsShield;
	bool m_bWasFollowing;
	float m_flNextFollowTime;
	float m_flYawModifier;
	float m_blindUntilTime;
	float m_blindStartTime;
	float m_blindHoldTime;
	float m_blindFadeTime;
	int m_blindAlpha;
	float m_allowAutoFollowTime;
	char m_autoBuyString[ MAX_AUTOBUY_LENGTH ];
	char *m_rebuyString;
	RebuyStruct m_rebuyStruct;
	bool m_bIsInRebuy;
	float m_flLastUpdateTime;
	char m_lastLocation[ MaxLocationLen ];
	float m_progressStart;
	float m_progressEnd;
	bool m_bObserverAutoDirector;
	bool m_canSwitchObserverModes;
	float m_heartBeatTime;
	float m_intenseTimestamp;
	float m_silentTimestamp;
	MusicState m_musicState;
	float m_flLastCommandTime[8];

};/* size: 2500, cachelines: 40, members: 190 */
/* Line - 2500 | Windows - 2480 */

/* <14ed87> ../cstrike/dlls/player.cpp:3407 */
class CWShield: public CBaseEntity
{
public:
	NOBODY virtual void Spawn(void);
	NOBODY virtual void EXPORT Touch(CBaseEntity *pOther);
public:
	/* <14e77d> ../cstrike/dlls/player.cpp:3410 */
	void SetCantBePickedUpByUser(CBaseEntity *pEntity, float time)
	{
		m_hEntToIgnoreTouchesFrom = pEntity;
		m_flTimeToIgnoreTouches = gpGlobals->time + time;
	}
public:
	EHANDLE m_hEntToIgnoreTouchesFrom;
	float m_flTimeToIgnoreTouches;
};/* size: 164, cachelines: 3, members: 3 */

extern char *m_szPoses[4];
extern WeaponStruct g_weaponStruct[MAX_WEAPONS];

extern int gEvilImpulse101;
extern char g_szMapBriefingText[512];
extern BOOL gInitHUD;
extern cvar_t *sv_aim;

extern int giPrecacheGrunt;
extern int gmsgWeapPickup;
extern int gmsgHudText;
extern int gmsgHudTextArgs;
extern int gmsgShake;
extern int gmsgFade;
extern int gmsgFlashlight;
//extern int gmsgFlashBattery;
//extern int gmsgResetHUD;
//extern int gmsgInitHUD;
//extern int gmsgViewMode;
//extern int gmsgShowGameTitle;
extern int gmsgCurWeapon;
//extern int gmsgHealth;
//extern int gmsgDamage;
//extern int gmsgBattery;
//extern int gmsgTrain;
extern int gmsgLogo;
extern int gmsgWeaponList;
extern int gmsgAmmoX;
//extern int gmsgDeathMsg;
extern int gmsgScoreAttrib;
extern int gmsgScoreInfo;
extern int gmsgTeamInfo;
//extern int gmsgTeamScore;
//extern int gmsgGameMode;
//extern int gmsgMOTD;
//extern int gmsgServerName;
extern int gmsgAmmoPickup;
extern int gmsgItemPickup;
//extern int gmsgHideWeapon;
extern int gmsgSayText;
extern int gmsgTextMsg;
extern int gmsgSetFOV;
extern int gmsgShowMenu;
extern int gmsgSendAudio;
extern int gmsgRoundTime;
extern int gmsgMoney;
extern int gmsgBlinkAcct;
extern int gmsgArmorType;
extern int gmsgStatusValue;
extern int gmsgStatusText;
extern int gmsgStatusIcon;
extern int gmsgBarTime;
extern int gmsgReloadSound;
extern int gmsgCrosshair;
extern int gmsgNVGToggle;
//extern int gmsgRadar;
extern int gmsgSpectator;
//extern int gmsgVGUIMenu;
extern int gmsgCZCareer;
//extern int gmsgCZCareerHUD;
extern int gmsgTaskTime;
//extern int gmsgTutorText;
extern int gmsgTutorLine;
//extern int gmsgShadowIdx;
extern int gmsgTutorState;
extern int gmsgTutorClose;
//extern int gmsgAllowSpec;
extern int gmsgBombDrop;
//extern int gmsgBombPickup;
extern int gmsgHostagePos;
//extern int gmsgHostageK;
extern int gmsgGeigerRange;
extern int gmsgSendCorpse;
//extern int gmsgHLTV;
//extern int gmsgSpecHealth;
//extern int gmsgForceCam;
//extern int gmsgADStop;
extern int gmsgReceiveW;
extern int gmsgScenarioIcon;
extern int gmsgBotVoice;
extern int gmsgBuyClose;
extern int gmsgItemStatus;
extern int gmsgLocation;
extern int gmsgSpecHealth2;
extern int gmsgBarTime2;
extern int gmsgBotProgress;
//extern int gmsgBrass;
//extern int gmsgFog;
//extern int gmsgShowTimer;

//NOBODY void player(entvars_t *pev);
//NOBODY void weapon_shield(entvars_t *pev);
//NOBODY void info_intermission(entvars_t *pev);
//NOBODY void player_loadsaved(entvars_t *pev);
//NOBODY void player_weaponstrip(entvars_t *pev);
//NOBODY void monster_hevsuit_dead(entvars_t *pev);

void OLD_CheckBuyZone(CBasePlayer *player);
void OLD_CheckBombTarget(CBasePlayer *player);
void OLD_CheckRescueZone(CBasePlayer *player);

void BuyZoneIcon_Set(CBasePlayer *player);
void BuyZoneIcon_Clear(CBasePlayer *player);
void BombTargetFlash_Set(CBasePlayer *player);
void BombTargetFlash_Clear(CBasePlayer *player);
void RescueZoneIcon_Set(CBasePlayer *player);
void RescueZoneIcon_Clear(CBasePlayer *player);
void EscapeZoneIcon_Set(CBasePlayer *player);
void EscapeZoneIcon_Clear(CBasePlayer *player);
void EscapeZoneIcon_Set(CBasePlayer *player);
void EscapeZoneIcon_Clear(CBasePlayer *player);
void VIP_SafetyZoneIcon_Set(CBasePlayer *player);
void VIP_SafetyZoneIcon_Clear(CBasePlayer *player);

NOBODY void LinkUserMessages(void);
void WriteSigonMessages(void);
void SendItemStatus(CBasePlayer *pPlayer);
const char *GetCSModelName(int item_id);
Vector VecVelocityForDamage(float flDamage);
int TrainSpeed(int iSpeed, int iMax);
const char *GetWeaponName(entvars_t *pevInflictor, entvars_t *pKiller);
void LogAttack(CBasePlayer *pAttacker, CBasePlayer *pVictim, int teamAttack, int healthHit, int armorHit, int newHealth, int newArmor, const char *killer_weapon_name);
void packPlayerItem(CBasePlayer *pPlayer, CBasePlayerItem *pItem, bool packAmmo);
bool CanSeeUseable(CBasePlayer *me, CBaseEntity *entity);
NOBODY void FixPlayerCrouchStuck(edict_t *pPlayer);
NOXREF BOOL IsSpawnPointValid(CBaseEntity *pPlayer, CBaseEntity *pSpot);
NOBODY void InitZombieSpawns(void);
NOBODY CBaseEntity *FindZombieSpawn(CBaseEntity *player, bool forceSpawn);
NOBODY edict_t *EntSelectSpawnPoint(CBaseEntity *pPlayer);
void SetScoreAttrib(CBasePlayer *dest, CBasePlayer *src);
NOXREF CBaseEntity *FindEntityForward(CBaseEntity *pMe);
float GetPlayerPitch(const edict_t *pEdict);
float GetPlayerYaw(const edict_t *pEdict);
int GetPlayerGaitsequence(edict_t *pEdict);
NOXREF const char *GetBuyStringForWeaponClass(int weaponClass);
NOXREF bool IsPrimaryWeaponClass(int classId);
NOXREF bool IsPrimaryWeaponId(int id);
NOXREF bool IsSecondaryWeaponClass(int classId);
NOXREF bool IsSecondaryWeaponId(int id);
NOXREF const char *GetWeaponAliasFromName(const char *weaponName);
NOXREF bool CurrentWeaponSatisfies(CBasePlayerWeapon *pWeapon, int id, int classId);

// refs
extern void (*CBasePlayer__UpdateClientData)(void);

#endif // PLAYER_H
