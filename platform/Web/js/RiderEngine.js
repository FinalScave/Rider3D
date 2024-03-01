
let lib = null

class Rider3DLib {
    static async load(thenPart) {
        fetch('wasm/rider3d.wasm')
            .then(response=>response.arrayBuffer())
            .then(bytes =>WebAssembly.compile(bytes))
            .then(module=>{
                console.log(module)
                const instance = new WebAssembly.Instance(module, {
                    env:{}
                })
                console.log(instance)
                lib = instance
                thenPart()
            })
            .catch(error => {
                console.error('Failed to load wasm module:', error);
            });
    }
}

class RiderEngine {
    constructor(canvasId, w, h, debug) {
        this.ptr = module.makeEngine(canvasId, w, h, debug)
    }
}