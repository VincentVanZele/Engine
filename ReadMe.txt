Bubble Bobble - 2DAE01 - Vincent Van Zele - Programming 4 - 2019/2020

This project englobes my current work on my own custom 2D-Engine based on Minigin.

**************************

Based on SDL (rendering / audio / different resources )

**************************

--- Specifications ---

-> Game : holds a list of scenes, that will be intitialized, updated and rendered;
	  at whatever time, any scene can be set as the main active one.

	-> Scenes : a scene holds, uses and updates game objects.

		-> GameObjects : are entities that will be loaded, updated and rendered through the whole game;
			 	they all hold a range of components depending on the use of those game objects. 

			-> Component Based Engine : components are identifiers that each have their own uses and logic,
						    attached to game objects, they describe them and determine their behavior and purpose.


--- Components ---

	-> TransformComponent : every game object has one by default;
				it holds any information about our game objects position, rotation, etc... movement in general.

	-> TextureComponent : when attached, the user can link any game object to a certain texture and all its settings.

	-> TextComponent : specific use of the TextureComponent that renders text as a texture.

	-> SpriteComponent : holds a variable range of animation sequences based on textures that will be rendered specifically to make animated sprites;
			     Animation defines the sprites settings (name, frames, time between frames, if it has to loop or not, the texture itself, etc...);
			     an animation hold a sequence of steps between frames, run or jump or die... and they all can be linked together with this component.

--- Managers ---

	-> GameTime : continuously holds the elapsedTime of the game and can be accessed whenever needed by every scene, object or component.

	-> SceneManager : manages every scene that are updated by the game loop, thus managing the updating of all the gameobjects and components.

	-> ResourceManager : manages the loading of all the SDL textures as well as the font that will be used in either the Text, the Texture or the Sprite Component.

	-> Renderer : manages the rendering of every SDL Textures and font depending on a position; On the other hand, Sprites depend on destination and source rectangles. 

	-> InputManager : manages Input from either the keyboard using SDL key codes or a controller using XInput, 
			  pre-defined commands determines how and what can be done. 

	-> Audio : plays, pauses or stops sound effects (Chunks) or music (Music) from SDL. WIP


--- Other ---

	"Structs.h" define a few helpful structures such as window info, float2-3-4, commands, buttons, etc...
	
	Minigins base project uses std::shared_ptr instead of raw pointers. I tried to keep it this way as often as possible because smart pointers are generally 
	better to use but raw pointers are in still in use sometimes for comfort.

