#include "invoker/RemoteControl.hpp"
#include "commands/LightCommands.hpp"
#include "commands/StereoCommands.hpp"
#include "commands/CeilingFanCommands.hpp"
#include "commands/MacroCommand.hpp"
#include <functional> // For Lambdas

// --- LAMBDA ADAPTER CLASS ---
// This allows us to use C++ Lambdas with our Command interface
class LambdaCommand : public Command {
    std::function<void()> executeFunc;
    std::function<void()> undoFunc;
public:
    LambdaCommand(std::function<void()> ex, std::function<void()> un) 
        : executeFunc(ex), undoFunc(un) {}
    void execute() override { executeFunc(); }
    void undo() override { undoFunc(); }
};

int main() {
    RemoteControl* remote = new RemoteControl();

    // --- 1. SETUP DEVICES ---
    Light* livingRoomLight = new Light("Living Room");
    Light* kitchenLight = new Light("Kitchen");
    CeilingFan* ceilingFan = new CeilingFan("Living Room");
    Stereo* stereo = new Stereo("Living Room");

    // --- 2. CREATE COMMANDS ---
    LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
    LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);
    
    LightOnCommand* kitchenLightOn = new LightOnCommand(kitchenLight);
    LightOffCommand* kitchenLightOff = new LightOffCommand(kitchenLight);

    CeilingFanHighCommand* ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
    CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

    StereoOnWithCDCommand* stereoOn = new StereoOnWithCDCommand(stereo);
    StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

    // --- 3. LOAD REMOTE SLOTS ---
    remote->setCommand(0, livingRoomLightOn, livingRoomLightOff);
    remote->setCommand(1, kitchenLightOn, kitchenLightOff);
    remote->setCommand(2, ceilingFanHigh, ceilingFanOff);
    remote->setCommand(3, stereoOn, stereoOff);

    // --- TEST 1: LIGHTS & UNDO ---
    std::cout << "\n--- TEST: Lights with Undo ---" << std::endl;
    remote->onButtonWasPushed(0); // Light On
    remote->offButtonWasPushed(0); // Light Off
    remote->undoButtonWasPushed(); // Should turn Light ON again!

    // --- TEST 2: CEILING FAN STATE ---
    std::cout << "\n--- TEST: Ceiling Fan State ---" << std::endl;
    remote->onButtonWasPushed(2); // Fan High
    remote->offButtonWasPushed(2); // Fan Off
    std::cout << "User changed mind, pressing undo..." << std::endl;
    remote->undoButtonWasPushed(); // Should go back to HIGH

    // --- TEST 3: MACRO COMMAND (PARTY MODE) ---
    std::cout << "\n--- TEST: Party Mode (Macro) ---" << std::endl;
    // Create the party array
    std::vector<Command*> partyOn = { livingRoomLightOn, stereoOn, ceilingFanHigh };
    std::vector<Command*> partyOff = { livingRoomLightOff, stereoOff, ceilingFanOff };
    
    MacroCommand* partyOnMacro = new MacroCommand(partyOn);
    MacroCommand* partyOffMacro = new MacroCommand(partyOff);

    remote->setCommand(4, partyOnMacro, partyOffMacro);

    std::cout << "Pushing Party ON..." << std::endl;
    remote->onButtonWasPushed(4); // Everything turns on
    std::cout << "Pushing Party UNDO..." << std::endl;
    remote->undoButtonWasPushed(); // Everything should turn off in reverse order

    // --- TEST 4: C++ LAMBDAS ---
    std::cout << "\n--- TEST: Lambda Commands ---" << std::endl;
    // We define the logic IN-LINE without creating new classes!
    // Format: new LambdaCommand( [EXECUTE LOGIC], [UNDO LOGIC] )
    
    Command* lambdaCmd = new LambdaCommand(
        [=]() { std::cout << "Lambda: TV is ON!" << std::endl; },  // Execute
        [=]() { std::cout << "Lambda: TV is OFF!" << std::endl; }  // Undo
    );

    remote->setCommand(5, lambdaCmd, lambdaCmd); // Using same for on/off just for demo
    remote->onButtonWasPushed(5);
    remote->undoButtonWasPushed();

    return 0;
}