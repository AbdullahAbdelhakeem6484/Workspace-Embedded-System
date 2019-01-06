#ifndef CALCULATOR_BLOCKS_H_
#define CALCULATOR_BLOCKS_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include "lcd.h"
#include "keypad.h"
/*Replace these includes with your own library*/
#include "math.h"

/*The limits on the inputs which you are set*/
#define MaxNumberOfDigits 16
#define MaxNumberOfOperands 12
#define MaxNumberOfOperations MaxNumberOfOperands-1

#define IsOperation(n) ((n=='*')||(n=='+')||(n=='-')||(n=='%'))

enum StageFlag{Reset,StartPoint,AnalyzePoint,CalculatePoint,DisplayPoint,ErrorPoint};
enum keys{EnterKey=13,EqualKey= '=' ,Numberkey,OperationKey};
enum Errors{ExcessedMaxNumberOfdigits,InvalidInput,OutofRange};	

extern uint8 Flag;

extern u32 powerOf(u8 x,u8 y); /*Used With ConvertToInt64()*/
void ResetData(); /*To get all the globel variables in .c file set to zero when doing new operation*/
void GetData(); /*Get the data from the keypad until pressing "equal key"*/
void SynchronousDisplay(u8 data); /*To display what you type in the LCD while storing the inputs*/
void Analyze(); /*To get the operands seperated from the operation to be able to know the operations which i am going to use*/
sint64 ConvertToInt64(u8 * ptr,u8 len); /*Converting series of seperate digits into a single number (1,1,5)=>115 */
void ThrowException(u8 *msg);/*Throw error message on LCD when error found*/
void Calculate(); /*Do the math*/
void DisplayResult();
#endif /* CALCULATOR_BLOCKS_H_ */