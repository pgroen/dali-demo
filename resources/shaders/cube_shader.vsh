attribute mediump vec3   aPosition;
uniform mediump mat4   uMvpMatrix;
varying mediump vec3 vTexCoord;

void main()
{
  vTexCoord.x = aPosition.x;
  vTexCoord.y = -aPosition.y; // convert to GL coords
  vTexCoord.z = aPosition.z;

  mediump vec4 vertexPosition = vec4(aPosition, 1.0);
  vec4 clipSpacePosition = uMvpMatrix * vertexPosition;
  // Writes 1.0, the maximum depth value, into the depth buffer.
  // This is an optimization to avoid running the fragment shader
  // for the pixels hidden by the scene's objects.
  gl_Position = clipSpacePosition.xyww;
}