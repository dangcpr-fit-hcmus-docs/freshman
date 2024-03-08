package objects
{
	import views.Assets;
	import starling.display.Image;
	import starling.display.Sprite;
	/**
	 *  Creating the bullet objects used by the fighter jet
	 * 	@author Peter Shodeinde
	 * 
	 * */
	public class Bullet extends Sprite
	{
		public function Bullet()
		{
			var img:Image = new Image(Assets.ta.getTexture("fireOne"));
			img.pivotX = width * 0.5;
			img.pivotY = height * 0.5;
			addChild(img);
		}
	}
}