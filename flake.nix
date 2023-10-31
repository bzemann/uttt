{
  description = "utt";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs {
        inherit system;
      };
    in
    {
      formatter.${system} = pkgs.nixpkgs-fmt;

      devShell.${system} = pkgs.mkShell {
        nativeBuildInputs = with pkgs; [
          cmake
          clang-tools
          gdb
        ];
        buildInputs = [ ];
      };
    };
}
