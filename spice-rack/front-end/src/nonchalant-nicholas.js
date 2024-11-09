export class Nicholas{
    #container = null;

    constructor(spiceRack){
        this.spiceRack = spiceRack;//fetch from localStorage
        this.numSpices = this.spiceRack.length;
        //this.recipes = [] //hold recipes of spices
    }
    render(){
        this.#container = document.createElement("div");
        this.#container.classList.add("container");
        this.#container.appendChild(this.#createSearch());
        this.#container.appendChild(this.#createSpiceSlots(5));
        return this.#container;
    }

    #createSearch(){
        const searchContainer = document.createElement("div");//textbar to search for spices
        searchContainer.classList.add("searchBox");
        const form = document.createElement("form");
        const searchBar = document.createElement("input");
        searchBar.id = "searchBar";
        searchBar.type = "text";
        searchBar.placeholder = "Search Spice...";
        searchBar.size = "50";
        form.appendChild(searchBar);

        // const spicesSelected = document.createElement("div");//this will hold the selcted spices
        // spicesSelected.id = "spiceBox";

        const searchButton = document.createElement("input");
        searchButton.type = "button";
        searchButton.value = "Retrieve";
        searchButton.size = "10";
        searchButton.onclick = () =>{

        };

        searchContainer.appendChild(form);
        searchContainer.appendChild(searchButton);
        // searchContainer.appendChild(spicesSelected);

        return searchContainer;
    }

    #createSpiceSlotItem(slot, spiceName){
        const spiceSlotItem = document.createElement("div");
        spiceSlotItem.classList.add("sliceSlotItem");
        spiceSlotItem.id = slot;
        spiceSlotItem.innerText = "Slot " + slot + ": " + spiceName;
        spiceSlotItem.addEventListener("click", () =>{
            alert(spiceName + " was selected");
        })
        return spiceSlotItem;
    }

    #createSpiceSlots(slots){
        const spiceSlots = document.createElement("div");
        spiceSlots.classList.add("spiceSlots");
        for(let i = 0; i < slots; i++){
            spiceSlots.appendChild(this.#createSpiceSlotItem(i+1, this.spiceRack[i]))
        }
        return spiceSlots;
    }

}
