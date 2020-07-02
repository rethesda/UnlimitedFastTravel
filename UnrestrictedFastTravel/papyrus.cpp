#include "pch.h"

namespace UFT
{
    static bool PP_HasOverride(StaticFunctionTag* base, SInt32 c)
    {
        switch (c) {
        case PFTOverrideCodes::kPFT_Combat:
            return pft_state.combat;
        case PFTOverrideCodes::kPFT_TakingDamage:
            return pft_state.taking_damage;
        case PFTOverrideCodes::kPFT_Location:
            return pft_state.location;
        case PFTOverrideCodes::kPFT_GuardsPursuing:
            return pft_state.guards_pursuing;
        case PFTOverrideCodes::kPFT_OverEncumbered:
            return pft_state.over_encumbered;
        case PFTOverrideCodes::kPFT_InAir:
            return pft_state.in_air;
        case PFTOverrideCodes::kPFT_WorldspaceTravel:
            return pft_state.worldspace_travel;
        }
        return false;
    }

    static void PP_SetOverride(StaticFunctionTag* base, SInt32 c, bool v)
    {
        switch (c) {
        case PFTOverrideCodes::kPFT_All:
            pft_state.combat = v;
            pft_state.taking_damage = v;
            pft_state.location = v;
            pft_state.guards_pursuing = v;
            pft_state.over_encumbered = v;
            pft_state.in_air = v;
            break;
        case PFTOverrideCodes::kPFT_Combat:
            pft_state.combat = v;
            break;
        case PFTOverrideCodes::kPFT_TakingDamage:
            pft_state.taking_damage = v;
            break;
        case PFTOverrideCodes::kPFT_Location:
            pft_state.location = v;
            break;
        case PFTOverrideCodes::kPFT_GuardsPursuing:
            pft_state.guards_pursuing = v;
            break;
        case PFTOverrideCodes::kPFT_OverEncumbered:
            pft_state.over_encumbered = v;
            break;
        case PFTOverrideCodes::kPFT_InAir:
            pft_state.in_air = v;
            break;
        case PFTOverrideCodes::kPFT_WorldspaceTravel:
            pft_state.worldspace_travel = v;
            break;
        default:
            return;
        }
        //Message("Setting PFT override: %ld %d", c, v);
    }

    static UInt32 PP_GetVersion(StaticFunctionTag* base)
    {
        return MAKE_PLUGIN_VERSION(
            PLUGIN_VERSION_MAJOR,
            PLUGIN_VERSION_MINOR,
            PLUGIN_VERSION_REVISION);
    }

    bool RegisterFunctions(VMClassRegistry* registry)
    {
        registry->RegisterFunction(
            new NativeFunction1<StaticFunctionTag, bool, SInt32>("HasOverride", "UnlimitedFastTravel", PP_HasOverride, registry));
        registry->RegisterFunction(
            new NativeFunction2<StaticFunctionTag, void, SInt32, bool>("SetOverride", "UnlimitedFastTravel", PP_SetOverride, registry));
        registry->RegisterFunction(
            new NativeFunction0<StaticFunctionTag, UInt32>("GetVersion", "UnlimitedFastTravel", PP_GetVersion, registry));

        return true;
    }
}