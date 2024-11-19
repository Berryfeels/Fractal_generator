# **Fractal Generator: Exploring the Infinite Beauty of Fractals**

## **Introduction**  
Fractal Generator is a computer graphics project aimed at visualizing the mathematical elegance of fractals. Fractals, known for their infinite complexity and self-similarity at every scale, are represented graphically in this program. The project provides an interactive and colorful experience, allowing users to explore the mesmerizing world of the Mandelbrot and Julia sets, with opportunities to extend to additional fractals.

---

## **Main Features**  

### **Fractal Rendering**  
- **Mandelbrot Set**: A classic fractal that reveals infinite intricacy upon zooming in.  
- **Julia Set**: Customizable fractals created by providing different parameters, offering diverse and unique patterns.  

---

### **Interactive Features**  
- **Zooming**: Use the mouse wheel to zoom in and out infinitely (within the limits of your system).  
- **Custom Parameters**: Pass parameters via the command line to modify the displayed fractal or its properties.  
- **Smooth Graphics**: Manage window transitions (e.g., minimizing, switching focus) seamlessly.
- Arrow keys for panning the view.  
- Continuous color shifting for mesmerizing animations. 

---

### **Color and Depth**  
- **Depth Visualization**: Color gradients to represent the fractal's iterative depth.  
- **Psychedelic Effects**: Experiment with vibrant color palettes for stunning visual effects.  

---

### **User-Friendly Controls**  
- **Keyboard and Mouse Interaction**:  
  - **Zoom**: Mouse wheel for zooming in and out.  
  - **ESC Key**: Cleanly exits the program.  
  - **Window Close Button**: Terminates the application gracefully.   

---

## **Technical Details**  
- Developed in **C** using the **MiniLibX library** for graphics rendering.  
- Utilizes mathematical concepts like **complex numbers** for fractal generation.  
- Fully optimized for smooth performance and clean memory management.  
- Complies with modern development standards, avoiding the use of global variables.  

---

## **How to Run**  
1. Clone the repository and navigate to the project directory.  
2. Compile the program using the provided **Makefile**:  
   ```bash
   make
   ```  
3. Run the program with the desired fractal type:  
   ```bash
   ./fractal_generator mandelbrot
   ```  
   Example for Julia sets with parameters:  
   ```bash
   ./fractal_generator julia 0.285 0.01
   ```  
4. For an invalid or missing argument, the program displays a list of available options.  

---

## **Conclusion**  
Fractal Generator combines mathematics and computer graphics, offering a window into the fascinating world of fractals. By exploring infinite patterns and colors, you’ll uncover the beauty of these intricate mathematical objects. Whether you're here to learn, play, or expand the program, Fractal Generator is a gateway to infinite creativity.  

Dive in, and let your imagination zoom!  
