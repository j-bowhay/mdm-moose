#include "mdmApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
mdmApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

mdmApp::mdmApp(InputParameters parameters) : MooseApp(parameters)
{
  mdmApp::registerAll(_factory, _action_factory, _syntax);
}

mdmApp::~mdmApp() {}

void
mdmApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"mdmApp"});
  Registry::registerActionsTo(af, {"mdmApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
mdmApp::registerApps()
{
  registerApp(mdmApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
mdmApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  mdmApp::registerAll(f, af, s);
}
extern "C" void
mdmApp__registerApps()
{
  mdmApp::registerApps();
}
