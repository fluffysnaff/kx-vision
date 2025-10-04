#include "PlayersTab.h"
#include "GuiHelpers.h"
#include "../../../libs/ImGui/imgui.h"
#include "../../Core/AppState.h"

namespace kx {
    namespace GUI {

        void RenderPlayersTab() {
            if (ImGui::BeginTabItem("Players")) {
                auto& settings = kx::AppState::Get().GetSettings();
                
                ImGui::Checkbox("Enable Player ESP", &settings.playerESP.enabled);
                
                if (settings.playerESP.enabled) {
                    ImGui::Separator();
                    if (ImGui::CollapsingHeader("Attitude Filter"))
                    {
                        ImGui::Checkbox("Show Friendly", &settings.playerESP.showFriendly);
                        ImGui::SameLine();
                        ImGui::Checkbox("Show Hostile", &settings.playerESP.showHostile);
                        ImGui::SameLine();
                        ImGui::Checkbox("Show Neutral", &settings.playerESP.showNeutral);
                        ImGui::Checkbox("Show Indifferent", &settings.playerESP.showIndifferent);
                    }
                    ImGui::Separator();
                    ImGui::Text("Player Filter Options");
                    ImGui::Checkbox("Show Local Player", &settings.playerESP.showLocalPlayer);
                    if (ImGui::IsItemHovered()) {
                        ImGui::SetTooltip("Show your own character in the ESP overlay.");
                    }

                    const char* gearModes[] = { "Off", "Compact (Stat Names)", "Compact (Top 3 Attributes)", "Detailed" };
                    ImGui::PushItemWidth(250.0f);
                    int gearModeInt = static_cast<int>(settings.playerESP.gearDisplayMode);
                    if (ImGui::Combo("Gear Display", &gearModeInt, gearModes, IM_ARRAYSIZE(gearModes))) {
                        settings.playerESP.gearDisplayMode = static_cast<GearDisplayMode>(gearModeInt);
                    }
                    ImGui::PopItemWidth();

                    ImGui::Separator();
                    RenderCategoryStyleSettings("Player Style", settings.playerESP.renderBox, settings.playerESP.renderDistance, settings.playerESP.renderDot, &settings.playerESP.renderHealthBar, &settings.playerESP.renderDetails, &settings.playerESP.renderPlayerName);
                }
                ImGui::EndTabItem();
            }
        }
    }
}