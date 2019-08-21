################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
source/%.obj: ../source/%.asm $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 --include_path="/Users/sems/Documents/Workspace/mbed/ARM/TI/TMS570LS1224_Example/include" --include_path="/Users/sems/Documents/Workspace/mbed/ARM/TI/TMS570LS1224_Example/source" --include_path="/Users/sems/Documents/Workspace/mbed/ARM/TI/TMS570LS1224_Example" --include_path="/Applications/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/%.obj: ../source/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 --include_path="/Users/sems/Documents/Workspace/mbed/ARM/TI/TMS570LS1224_Example/include" --include_path="/Users/sems/Documents/Workspace/mbed/ARM/TI/TMS570LS1224_Example/source" --include_path="/Users/sems/Documents/Workspace/mbed/ARM/TI/TMS570LS1224_Example" --include_path="/Applications/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


