#include <imgui.h>
#include <string>
#include <uvw.hpp>

#ifdef __cplusplus
extern "C" {
#endif
#include <quickjs/quickjs.h>
#ifdef __cplusplus
}
#endif

class Window {
public:
    Window(const std::string& title, int width, int height);

protected:
    bool initGLFW();
    bool create();
    bool initImGUI();

private:
    int mWidth;
    int mHeight;
    std::string mTitle;
    struct GLFWwindow* mWindow;
    uvw::Loop mLoop;                //uv loop instance
};
