// A browser without WebGPU (iOS 18 Safari, Firefox Android): navigator.gpu is gone.
Object.defineProperty(Navigator.prototype, 'gpu', { configurable: true, get: () => undefined });
