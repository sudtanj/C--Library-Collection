#include <iostream>
#define GLEW_STATIC
#include <GLFW\GLEW\include\GL\glew.h>
#include <GLFW\glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
const GLchar* vertexShaderSource = 
"#version 430 core\r\n"
"in layout (location = 0) vec3 position;\n"
"in layout (location = 1) vec3 color;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"gl_Position=vec4(position, 1.0);\n"
"ourColor=color;\n"
"}\n";

const GLchar* fragmentShaderSource = 
"#version 430 core\r\n"
""
"out vec4 daColor;\n"
"in vec3 ourColor;"
""
"void main()"
"{"
"daColor = vec4(ourColor,1.0f);" 
"}";

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	GLFWwindow* window = glfwCreateWindow(800, 800, "Triangle", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Window Creation Failed!" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "failed to load" << std::endl;
		return -1;
	}
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	//triangle
	GLfloat vertices[] = {
		//red
		0.0,0.90,0.0,
		1.0f,0.0f,0.0f,
		0.2f,0.70f,0.0f,
		1.0f,0.0f,0.0f,
		-0.2f,0.70f,0.0f,
		1.0f,0.0f,0.0f,
		//red
		0.0f,0.50f,0.0f,
		1.0f,0.0f,0.0f,
		0.2f,0.70f,0.0f,
		1.0f,0.0f,0.0f,
		-0.2f,0.70f,0.0f,
		1.0f,0.0f,0.0f,
		//pink
		-0.2f,0.70f,0.0f,
		1.00f, 0.00f, 1.00f,
		0.0f,0.50f,0.0f,
		1.00f, 0.00f, 1.00f,
		-0.4f,0.50f,0.0f,
		1.00f, 0.00f, 1.00f,
		//yellow
		0.2f,0.70f,0.0f,
		1.00f, 1.00f, 0.00f,
		0.4f,0.50f,0.0f,
		1.00f, 1.00f, 0.00f,
		0.0f,0.50f,0.0f,
		1.00f, 1.00f, 0.00f,
		//blue
		-0.4f,0.50f,0.0f,
		0.00f, 0.00f, 1.00f,
		-0.2f,0.30f,0.0f,
		0.00f, 0.00f, 1.00f,
		-0.6f,0.30f,0.0f,
		0.00f, 0.00f, 1.00f,
		//blue
		-0.2f,0.30f,0.0f,
		0.00f, 0.00f, 1.00f,
		0.0f,0.50f,0.0f,
		0.00f, 0.00f, 1.00f,
		-0.4f,0.50f,0.0f,
		0.00f, 0.00f, 1.00f,
		//blue light
		0.0f,0.50f,0.0f,
		0.00f, 1.00f, 1.00f,
		-0.2f,0.30f,0.0f,
		0.00f, 1.00f, 1.00f,
		0.2f,0.30f,0.0f,
		0.00f, 1.00f, 1.00f,
		//green
		0.2f,0.30f,0.0f,
		0.00f, 1.00f, 0.00f,
		0.4f,0.50f,0.0f,
		0.00f, 1.00f, 0.00f,
		0.0f,0.50f,0.0f,
		0.00f, 1.00f, 0.00f,
		//green
		0.4f,0.50f,0.0f,
		0.00f, 1.00f, 0.00f,
		0.2f,0.30f,0.0f,
		0.00f, 1.00f, 0.00f,
		0.6f,0.30f,0.0f,
		0.00f, 1.00f, 0.00f,
	};
	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(char*)(3 * sizeof(GLfloat)));
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* adapter[1];
	adapter[0] = vertexShaderSource;
	glShaderSource(vertexShader, 1, adapter, 0);
	adapter[0] = fragmentShaderSource;
	GLint success;
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (success != GL_TRUE) {
		GLint infolength;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &infolength);
		GLchar* buffer = new GLchar[infolength];
		std::cout << buffer << std::endl;
		GLsizei buffersize;
		glGetShaderInfoLog(vertexShader, infolength, &buffersize, buffer);
		std::cout << buffer << std::endl;
		std::cout << buffersize << "failed to load" << std::endl;
	}
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, adapter, 0);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (success != GL_TRUE) {
		GLint infolength;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &infolength);
		GLchar* buffer = new GLchar[infolength];
		glGetShaderInfoLog(fragmentShader, infolength, nullptr, buffer);
		std::cout << buffer << std::endl;
		std::cout << "failed to load" << std::endl;
	}
	//test
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glViewport(0, 0, width, height);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices)/18);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, 
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}