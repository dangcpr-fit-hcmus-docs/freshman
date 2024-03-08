package objects
{
	import models.PlayingGame;
	import views.Assets;
	
	import starling.core.Starling;
	import starling.display.Image;
	import starling.display.Sprite;
	/**
	 * Creating the spaceship fighter object
	 * @author Peter Shodeinde
	 * 
	 * */
	public class SpaceShip extends Sprite
	{
		private var playGame:PlayingGame;
		public function SpaceShip(playGame:PlayingGame)
		{
			this.playGame = playGame;
			
			var img:Image = new Image(Assets.ta.getTexture("spaceship"));
			img.pivotX = img.width * 0.5;
			img.pivotY = img.height * 0.5;
			addChild(img);
			
		}
		
		public function update():void
		{
			/**
			 * Getting the mouse event from the flash stage not Starling, 
			 * starling contain touch event for interaction
			 * 			 
			*/
			x += (Starling.current.nativeStage.mouseX - x) * 0.3;
			y += (Starling.current.nativeStage.mouseY - y) * 0.3;
			
		}
	}
}