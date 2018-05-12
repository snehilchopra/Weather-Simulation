#          DEVELOPMENT
## Log - 1
### Aim :
The main objective for this week was to **setup the particle system** using the OpenGL and GLUT frameworks. The particle system basically comprised of the rain drops, where each drop was a single object rendered various attributes, such as **color, (x,y,z) coordinates, gravity etc**. Lastly, I am currently in the process of adding the **functionality of keys** , so that the entire simulation can be controlled and manipulated as per the user's desires.

### Challenges :
The main difficulties that I encountered along the way were mostly contained in **figuring out how the OpenGL Library operates**: how objects are initialized and created, the callback functions that dynamically take in input from the user and drawing different particles using the functions that OpenGL lends to our disposal.
All in all, in that regard, once the concept was grasped well, I was able to manage the code that followed.

## Log - 2
### Aim :
The main objective this week was to establish the **functionality of other attributes of weather** such as snow,  thunder, wind etc. To enhance the scene and render it more realistic, I added background sounds for each scenario resulting from any combination of weather.

### Challenges :
A **major code restructuring** was underway this week. It was probably **figuring out the orientation of the 3-D world** in my project that consumed most of my time, since I had to eliminate the direct calls to the glut callback functions after I realized that Openframeworks calls glut functions under the hood. Consequently, I had to **add the fundamental ofApp source files** and then adjust my code accordingly. On the contrary, once the code re-orientation was completed, I found more readable and well-structured code at my disposal, and I was able to grasp and work efficiently with entire coordinate system, without having to throw in different viewports and projection matrices.

## Log - 3
### Aim :
The main objective this week was to **document the code properly**, adding all **necessary comments and formatting** wherever necessary. Moreover, another task to be accomplished was to **separate different elements of weather into different, separate source files** of their own, resulting in **better decomposition**. Lastly, an **instructions manual and dynamic control panel** was of utmost importance.

### Challenges :
Probably the most time consuming part was **figuring out how to add fog, clouds and a grass simulation to my project**.  Unfortunately, it required the knowledge of advanced topics of **shaders** and due to the **overall workload of courses**, I was not able to achieve it. However, the other parts of the project function smoothly and I feel quite contented with them.
