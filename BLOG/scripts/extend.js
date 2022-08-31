hexo.extend.injector.register('body_end', '<canvas class="fireworks" style="position: fixed;left: 0;top: 0;z-index: 99999; pointer-events: none;" ></canvas> ', 'default');
hexo.extend.injector.register('body_end', '<script type="text/javascript" src="//cdn.bootcss.com/animejs/2.2.0/anime.min.js"></script> ', 'default');
hexo.extend.injector.register('body_end', '<script type="text/javascript" src="/js/cursor/fireworks.js"></script>', 'default');
hexo.extend.injector.register('body_end', '<canvas id = "background" style = "position:fixed;top:0;left:0;width:100vw;height:100vh;pointer-events:none;z-index:99998"> </canvas > ', 'default');
hexo.extend.injector.register('body_end', '<script src="/js/bg/background.js"></script>', 'default');
hexo.extend.injector.register('body_end', '<div id="cursor"></div>', 'default');
hexo.extend.injector.register('body_end', '<script src="/css/cursor/mouth.css"></script>', 'default');
hexo.extend.injector.register('body_end', '<script src="/js/cursor/mouth.js"></script>', 'default');
