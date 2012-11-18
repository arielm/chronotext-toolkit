
package chronotext.android.cinder;

import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.content.res.AssetManager;
import chronotext.android.gl.GLRenderer;

public class CinderRenderer extends GLRenderer
{
  public static final int EVENT_ATTACHED = 1;
  public static final int EVENT_DETACHED = 2;
  public static final int EVENT_PAUSED = 3;
  public static final int EVENT_RESUMED = 4;
  public static final int EVENT_SHOWN = 5;
  public static final int EVENT_HIDDEN = 6;
  public static final int EVENT_DESTROYED = 7;

  Context context;
  Object listener;

  public CinderRenderer(Context context, Object listener)
  {
    this.context = context;
    this.listener = listener;
  }

  public void launch()
  {
    launch(context.getAssets(), listener);
  }

  public void init(GL10 gl, int width, int height)
  {
    init(width, height);
    initialized = true;
  }

  public void draw(GL10 gl)
  {
    draw();
  }

  public void attached()
  {
    event(EVENT_ATTACHED);
    attached = true;
    hidden = false;
  }

  public void detached()
  {
    event(EVENT_DETACHED);
    attached = false;
  }

  public void paused()
  {
    event(EVENT_PAUSED);
    resumed = false;
  }

  public void resumed()
  {
    event(EVENT_RESUMED);
    resumed = true;
    hidden = false;
  }

  public void destroyed()
  {
    event(EVENT_DESTROYED);
  }

  public void shown()
  {
    event(EVENT_SHOWN);
    hidden = false;
  }

  public void hidden()
  {
    event(EVENT_HIDDEN);
    hidden = true;
  }

  // ---------------------------------------- JNI ----------------------------------------

  public native void launch(AssetManager assets, Object listener);

  public native void init(int width, int height);

  public native void draw();

  public native void event(int id);

  public native void addTouch(float x, float y);

  public native void updateTouch(float x, float y);

  public native void removeTouch(float x, float y);

  public native void handleMessage(int what, String body);
}