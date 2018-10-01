#pragma once

#include <string>
#include <map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

/**
  Provides easy and convenient way to handle OpenGL Window creation and basic scene management (init, render and release).
 */

class OpenGLWindow
{
public:
	
	///* \brief Constructor of the class, initializes internal structures.
	OpenGLWindow();

	/** \brief  Creates a window with OpenGL context with given title and context version. 
	 *  \param  windowTitle    Title of a created window
	 *  \param  majorVersion   OpenGL context major version
	 *  \param  minorVersion   OpenGL context minor version
	 *  \param  showFullscreen Tells, whether the window should be shown in fullscreen
     *  \return True, if window has been created or false otherwise
	 */
	bool createOpenGLWindow(const std::string& windowTitle, int majorVersion, int minorVersion, bool showFullscreen);

	/** \brief  Creates a window with OpenGL context with given title and context version.
	*   \param  windowTitle    Title of a created window
	*   \return Pointer to GLFW window or nullptr, if the window does not exist yet.
	*/
	GLFWwindow* getWindow() const;

	//* \brief Runs the whole application. Contains the main application loop.
	void runApp();

	/** Initializes OpenGL Scene. This function is not implemented, but it depends on
	 *  the tutorial, what are the contents of this function.
	*/
	void initializeScene();
	
	/** Performs rendering of OpenGL Scene. This function is not implemented, but it depends on
	*  the tutorial, what are the contents of this function.
	*/
	void renderScene();
	
	/** Releases OpenGL Scene, i.e. cleans up after itself and releases all used resources. This function
	*  is not implemented, but it depends on the tutorial, what are the contents of this function.
	*/
	void releaseScene();

	/** Handles input in the application. This function is not implemented, but it depends on
	*   the tutorial, what are the contents of this function.
	*/
	void handleInput();

	/** \brief  Checks, if specified key is currently pressed
	*   \param  keyCode GLFW code of the key to check
	*   \return True, if key is pressed, or false otherwise.
	*/
	bool keyPressed(int keyCode) const;

	/** \brief  Checks, if specified key was pressed. This function won't return true again, unless the key has been released and pressed again.
	*   \param  keyCode GLFW code of the key to check
	*   \return True, if key was pressed once, or false otherwise.
	*/
	bool keyPressedOnce(int keyCode);

	/** \brief  Function, that gets called, when the size of the window changes. This function is also
	*   left un-implemented and user should implement it.
	*   \param  window Pointer to GLFWwindow, size of which has changed
	*   \param  width  New window width (in pixels)
	*   \param  height New window height (in pixels)
	*/
	void onWindowSizeChanged(GLFWwindow* window, int width, int height);

	/** \brief Closes application window and releases all resources. Also sets the error flag, if error has occured.
	*   \param hasErrorOccured Should be true, if an error has occured (default is false).
	*/
	void closeWindow(bool hasErrorOccured = false);

	/** \brief  Gets the error flag.
	*   \return True, if error has occured, or false otherwise.
	*/
	bool hasErrorOccured() const;

	/** \brief  Gets the projection matrix for the current window size.
	*   \return Projection matrix;
	*/
	glm::mat4 getProjectionMatrix() const;

	float sof(float value) const;
	double sof(double value) const;
	double getTimeDelta() const;
	int getFPS() const;

private:
	GLFWwindow* _window = nullptr; ///< Pointer to GLFWwindow, nullptr by default
	bool _keyWasPressed[512]; ///< Array of bools, used by keyPressedOnce function
	bool _hasErrorOccured = false; ///< Error flag, indicates, if any kind of error has occured

	glm::mat4 _projectionMatrix;
	void recalculateProjectionMatrix();

	double _lastFrameTime;
	double _lastFrameTimeFPS;
	double _timeDelta;
	int _FPS;
	int _nextFPS;
	void updateDeltaTimeAndFPS();

	//* \brief Static method, that is set as callback to GLFW framework about window size changed.
	static void onWindowSizeChangedStatic(GLFWwindow* window, int width, int height);

	static std::map<GLFWwindow*, OpenGLWindow*> _windows; ///< std::map used to map GLFWwindow pointers to OpenGLWindow (our class)
};