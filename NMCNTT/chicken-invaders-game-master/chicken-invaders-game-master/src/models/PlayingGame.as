package models
{
	//creating the start game menu for our game
	
	import controller.IState;
	
	import flash.display.Stage;
	import flash.events.MouseEvent;
	
	import lib.BulletManager;
	import lib.ChickenManager;
	import lib.CollisionManager;
	import lib.ExplosionManager;
	
	import objects.Background;
	import objects.Score;
	import objects.SpaceShip;
	
	import starling.core.Starling;
	import starling.display.Sprite;
	import starling.events.Event;
	
	import views.Game;
	/**
	 * Playgame state of the game
	 * @author Peter Shodeinde
	 * 
	 * */
	
	public class PlayingGame extends Sprite implements IState
	{
		
		public var	game:Game;
		private var background:Background;
		public var fighter:SpaceShip;
		public var bulletManager:BulletManager;
		private var ns:Stage;
		//variable for the mouse event for the firing the bullet
		public var fire:Boolean = false;
		public var chickenManager:ChickenManager;
		private var collisionManager:CollisionManager;
		public var score:Score;
		public var explosionManager:ExplosionManager; 		
		public function PlayingGame(game:Game)
		{
			this.game = game;
			addEventListener(Event.ADDED_TO_STAGE, init)
		}
		// Creating an instance of the game assets and its engine
		private function init(event:Event):void
		{
			ns = Starling.current.nativeStage; // Getting the native MouseEvent from the staling library
			
			background = new Background();
			addChild(background);
		
			fighter = new SpaceShip(this);
			addChild(fighter);
			
			bulletManager = new BulletManager(this);
			chickenManager = new ChickenManager(this);
			collisionManager = new CollisionManager(this);
			explosionManager = new ExplosionManager(this);
			
			// adding the score to the play screen
			score = new Score();			
			addChild(score);
			score.x = 950;  
			ns.addEventListener(MouseEvent.MOUSE_DOWN, onDown);		
			ns.addEventListener(MouseEvent.MOUSE_UP,onUP);
			
		}
		// Mouse down effect for the fire object in the game
		private function onDown(event:MouseEvent):void
		{
			fire = true;
		}
		// Mouse up effect for the fire object in the game
		private function onUP(event:MouseEvent):void
		{
			fire = false;
			bulletManager.count = 0;
			
		}
		// to displace the content of the game on the stage
		public function update():void
		{
			background.update();
			fighter.update();
			bulletManager.update();
			chickenManager.update();
			collisionManager.update();
			
		}
		
		// remove instance of the game object from the game to preserve the memory
		public function destroy():void
		{
			ns.removeEventListener(MouseEvent.MOUSE_DOWN, onDown);		
			ns.removeEventListener(MouseEvent.MOUSE_UP,onUP);
			bulletManager.destroy();
			chickenManager.destroy();
			removeFromParent(true);
		}
	}
}