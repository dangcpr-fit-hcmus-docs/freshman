package models
{
	//creating the start game menu for our game
	
	import controller.IState;
	
	import objects.Background;
	
	import starling.core.Starling;
	import starling.display.Button;
	import starling.display.Sprite;
	import starling.events.Event;
	import starling.text.TextField;
	
	import views.Assets;
	import views.Game;
	/**
	 * GameOver state of the game
	 * @author Peter Shodeinde
	 * 
	 * */
	
	public class GameOver extends Sprite implements IState
	{
		
		private var	game:Game;
		private var background:Background;
		private var overText:TextField;
		private var tryAgainButton:Button;
		public function GameOver(game:Game)
		{
			this.game = game;
			addEventListener(Event.ADDED_TO_STAGE, init)
		}
		
		private function init(event:Event):void
		{
			background = new Background();
			addChild(background);
			
			overText = new TextField(800, 200, "GAME OVER","Verdana", 70, 0xFFFFFF);
			overText.hAlign = "center";
			overText.y = 200;
			addChild(overText);
			
			tryAgainButton = new Button(Assets.ta.getTexture("tryAgainButton"));
			tryAgainButton.addEventListener(Event.TRIGGERED, tryAgain);
			tryAgainButton .pivotX = tryAgainButton.width* 0.5;
			tryAgainButton.x = 400;
			tryAgainButton.y = 450;
			addChild(tryAgainButton);
				
		}
		// when the player clicks the try again button. the state of the game changes.
		public function tryAgain(event:Event):void
		{
			
			game.changeState(Game.PLAYING_GAME_MODEL);
		}
		public function update():void
		{
			background.update();
		}
		// remove from the screen to preserve the memory 
		public function destroy():void
		{
			removeFromParent(true);
		}
	}
}