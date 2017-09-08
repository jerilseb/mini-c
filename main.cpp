
#include <iostream>
#include "codegen.h"
#include "node.h"
#include <fstream>

using namespace std;

extern int yyparse();
extern NBlock* programBlock;

//void createCoreFunctions(CodeGenContext& context);

int main(int argc, char **argv)
{
    yyparse();
    cout << programBlock << endl;
    // see http://comments.gmane.org/gmane.comp.compilers.llvm.devel/33877
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();
    CodeGenContext context;
    //createCoreFunctions(context);
    std::string asmCode = context.generateCode(*programBlock);
    //context.generateCode(*programBlock);
    //acontext.runCode();
    ofstream fout("out.ll");
    fout << asmCode;    
    fout.close();
    return 0;
}

