#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FOilRigSimulatorModule : public FDefaultGameModuleImpl
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
