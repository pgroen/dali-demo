/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/**
 * @file text-label-example.cpp
 * @brief Basic usage of TextLabel control
 */

// EXTERNAL INCLUDES
#include <dali-toolkit/dali-toolkit.h>
#include <dali/public-api/text-abstraction/text-abstraction.h>

using namespace Dali;
using namespace Dali::Toolkit;

/**
 * @brief The main class of the demo.
 */
class TextLabelExample : public ConnectionTracker
{
public:

  TextLabelExample( Application& application )
  : mApplication( application )
  {
    // Connect to the Application's Init signal
    mApplication.InitSignal().Connect( this, &TextLabelExample::Create );
  }

  ~TextLabelExample()
  {
    // Nothing to do here.
  }

  /**
   * One-time setup in response to Application InitSignal.
   */
  void Create( Application& application )
  {
    Stage stage = Stage::GetCurrent();

    TextLabel label = TextLabel::New();
    label.SetParentOrigin( ParentOrigin::CENTER );
    stage.Add( label );

    label.SetProperty( TextLabel::PROPERTY_MULTI_LINE, true );

    label.SetProperty( TextLabel::PROPERTY_TEXT, "A Quick Brown Fox Jumps Over The Lazy Dog" );

    // TODO
    //Property::Value labelText = label.GetProperty( TextLabel::PROPERTY_TEXT );
    //std::cout << "Got text from label: " << labelText.Get< std::string >() << std::endl;
  }

private:

  Application& mApplication;
};

void RunTest( Application& application )
{
  TextLabelExample test( application );

  application.MainLoop();
}

/** Entry point for Linux & Tizen applications */
int main( int argc, char **argv )
{
  Application application = Application::New( &argc, &argv );

  RunTest( application );

  return 0;
}
