1.mesa and opengl
    1.vmware 12 supportes opengl3.3 
      https://www.mesa3d.org/vmware-guest.html
      a)vmwgfx >2.9.0
      b)mesa with the upeated svga gallium driver
    otherwise Opengl2.1 is supported.
    2.vmware 15 ...
2.mesa and scons
    https://www.mesa3d.org/install.html
    scons:
        a) python >2.7 or 3.5
        b) scons, mako. (pip install xxx)
        c) option:
            virtuenv
        d).... xxxx>=xx.xxx
3.mesa and meson
    python >3.5
    meson(pip install meson)
    ninja
    xxx >= xxxx.xxx
    ....
4.core profile file:
    vmware 12 + CentOS 7.6
    > glxinfo -B

    ....
    ....
        Max core profile version: 0.0 (!!!!!! not support Core Poofile Mode)
        Max compat profile version: 2.1 (!!!!!! Just 2.1)
        OpenGL version string: 2.1 Mesa 18.0.5 (!!!!!! OpenGL 2.1)
    ....
    


