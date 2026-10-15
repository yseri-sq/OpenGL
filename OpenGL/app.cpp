#include <iostream>
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int g_windowSizeX = 800;
int g_windowSizeY = 600;

void glWindowSizeCallback(GLFWwindow* pWindow, int width, int height) {
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}
 
int main() {
    if (!glfwInit()) {
        std::cout << "glfwInt failed" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "OpenGL Project", NULL, NULL);
    if (pWindow == NULL) {
        std::cerr << "glfwCreateWindow failed" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(pWindow, glWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    glfwMakeContextCurrent(pWindow);

    glfwSetFramebufferSizeCallback(pWindow, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "gladLoadGLLoader failed" << std::endl;
        return -1;
    }

    std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    float red = 0.2f;
    float green = 0.3f;
    float blue = 0.3f;

    while (!glfwWindowShouldClose(pWindow)) {
        if (glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(pWindow, true);
        if (glfwGetKey(pWindow, GLFW_KEY_1) == GLFW_PRESS) {
            red = 0.6f; green = 0.1f; blue = 0.1f;
        }
        if (glfwGetKey(pWindow, GLFW_KEY_2) == GLFW_PRESS) {
            red = 0.1f; green = 0.6f; blue = 0.1f;
        }
        if (glfwGetKey(pWindow, GLFW_KEY_3) == GLFW_PRESS) {
            red = 0.1f; green = 0.1f; blue = 0.6f;
        }

        glClearColor(red, green, blue, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    return 0;
}
